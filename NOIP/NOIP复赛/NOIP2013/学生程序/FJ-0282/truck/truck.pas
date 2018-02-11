program ex;
const maxv=maxlongint div 2;
var q,i,j,m,n,k,x,y,z:longint;
    map,map2:array[0..2000,0..2000] of longint;
    dis:array[0..2000] of longint;
    w:array[0..10000] of boolean;
    w2:array[0..10000] of boolean;
    a:array[0..100003] of longint;

function min(a,b:longint):longint;
begin
 if a<b then exit(a) else exit(b);
end;
procedure dij(x:longint);
var l,r,i,j,k:longint;
begin
 r:=0;
 for i:=1 to n do
 begin
  dis[i]:=0;
  if (i<>x)and(map[x,i]<>maxv) then
   begin
    inc(r);
    a[r]:=i;
    dis[i]:=map[x,i];
    w2[i]:=true;
   end;
 end;
 dis[x]:=maxv;
 l:=0;
 while l<>r do
  begin
   l:=l+1;
   if i=100003 then l:=1;
   k:=a[l];
   for j:=1 to n do
    if (dis[j]<min(dis[k],map[k,j])) then
     begin
      dis[j]:=min(dis[k],map[k,j]);
      if not w2[j] then
       begin
        inc(r);
        if r=100003 then r:=1;
        a[r]:=j;
        w2[j]:=true;
       end;
    end;
  w2[k]:=false;
 end;
 for i:=1 to n do
  begin
   map2[x,i]:=dis[i];
   map2[i,x]:=dis[i];
  end;
end;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
 rewrite(output);
  read(n,m);
  if n<=2000 then
begin

  for i:=1 to n do
   for j:=1 to n do
    begin
     if i<>j then map2[i,j]:=-maxv;
     map[i,j]:=map2[i,j];
    end;
  for i:=1 to m do
   begin
    read(x,y,z);
    if z>map[x,y] then
     begin
      map[x,y]:=z;
      map[y,x]:=z;
     end;
   end;
  read(q);
  for i:=1 to q do
   begin
    read(x,y);
    if x>y then begin j:=x;x:=y;y:=j; end;
    if map2[x,y]=-maxv then
      dij(x);
    if map2[x,y]=-maxv then writeln(-1) else
      writeln(map2[x,y]);
   end;

end;

 close(input);
 close(output);
end.
