program saf;
var i,n,m,j,k,q1,l1,zx,xz:longint;
    x,y,z:array[1..50010]of longint;
    map,e:array[1..3010,1..3010]of longint;
    d,c:array[1..3010]of boolean;
    p,q:array[0..1500000]of longint;
    f:array[1..3010]of longint;
 procedure swap(var xx,yy:longint);
 var tt:longint;
 begin
  tt:=xx;xx:=yy;yy:=tt;
 end;
 procedure sort(l,r:longint);
 var i1,j1,xx:longint;
 begin
  i1:=l;j1:=r;
  xx:=z[(l+r)shr 1];
  while i1<j1 do
   begin
    while xx<z[i1] do inc(i1);
    while xx>z[j1] do dec(j1);
    if i1<=j1 then
     begin
      swap(x[i1],x[j1]);
      swap(y[i1],y[j1]);
      swap(z[i1],z[j1]);
      inc(i1);dec(j1);
     end;
   end;
  if i1<r then sort(i1,r);
  if j1>l then sort(l,j1);
 end;
 procedure bfs(xx:longint);
 var i1,j1,f,r:longint;
 begin
  f:=0;r:=1;
  q[r]:=xx;p[r]:=maxlongint;
  for i1:=1 to n do
   c[i1]:=true;
  c[xx]:=false;
  repeat
   inc(f);
   for i1:=1 to n do
    if (c[i1])and(map[q[f],i1]<>0) then
     begin
      inc(r);
      q[r]:=i1;
      c[i1]:=false;
      if map[q[f],i1]<p[f] then
       begin
        if e[xx,i1]<>0 then
        begin
         if e[xx,i1]>map[q[f],i1] then
         begin
          e[xx,i1]:=map[q[f],i1];
          e[i1,xx]:=map[q[f],i1];
         end;
        end
         else
          begin
           e[xx,i1]:=map[q[f],i1];
           e[i1,xx]:=map[q[f],i1];
          end;
         p[r]:=map[q[f],i1];
       end
      else
       begin
       if e[xx,i1]<>0 then
        begin
        if e[xx,i1]>p[f] then
         begin
          e[xx,i1]:=p[f];
          e[i1,xx]:=p[f];
         end;
        end
        else
          e[xx,i1]:=p[f];
          e[i1,xx]:=p[f];
        p[r]:=p[f];
       end;
     end;
  until f=r;
 end;
begin
 assign(input,'truck.in');
 reset(input);
 read(n,m);
 for i:=1 to n do
  begin c[i]:=true;d[i]:=true;f[i]:=i;end;
 for i:=1 to m do
   read(x[i],y[i],z[i]);
 sort(1,m);
 for i:=1 to m do
  begin
   if (map[x[i],y[i]]=0) then
    if f[x[i]]<>f[y[i]] then
    begin
      map[x[i],y[i]]:=z[i];
      map[y[i],x[i]]:=z[i];
      inc(l1);q1:=f[y[i]];
      for j:=1 to n do
       if f[j]=q1 then f[j]:=f[x[i]];
    end;
   if l1=n-1 then break;
  end;
 for i:=1 to n  do
  d[i]:=true;
 for i:=1 to n do
  if d[i] then
   begin
    d[i]:=false;
    bfs(i);
   end;
 assign(output,'truck.out');
 rewrite(output);
 read(q1);
 for i:=1 to q1 do
  begin
   read(zx,xz);
   if e[zx,xz]<>0 then writeln(e[zx,xz])
    else
     writeln('-1');
  end;
 close(input);
 close(output);
end.
