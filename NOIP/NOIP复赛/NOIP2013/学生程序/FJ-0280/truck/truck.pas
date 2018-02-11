program work;
type dota=^node;
    node=record
        x,d:longint;
        next:dota;
        end;
var son:array[0..10009] of dota;
    q:array[0..10009] of longint;
    d:array[0..10009] of boolean;
    i,j,n,m,x,y,k,l,r,mid,h,t,now:longint;
procedure init;
begin
 assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input);
  rewrite(output);
end;
procedure oover;
begin
 close(input);
 close(output);
end;
function ok(w:longint):boolean;
var i,j:longint;p:dota;
begin
 for i:=0 to n+1 do d[i]:=false;
 h:=0;t:=1;
 q[1]:=x;
 d[x]:=true;
 while h<>t do
 begin
  inc(h);
  if h=10001 then h:=1;
  now:=q[h];
  p:=son[now];
  while p<>nil do
  begin
   i:=p^.x;
   if (not d[i])and(p^.d>=w) then
   begin
    d[i]:=true;

     inc(t);
     if t=10001 then t:=1;
     q[t]:=i;

   end;
   p:=p^.next;
  end;
 end;
 if d[y] then exit(true);
 exit(false);
end;
procedure mmake(x,y,k:longint);
var p:dota;i,j:longint;
begin
 new(p);
 p^.x:=y;
 p^.d:=k;
 p^.next:=son[x];
 son[x]:=p;
 new(p);
 p^.x:=x;
 p^.d:=k;
 p^.next:=son[y];
 son[y]:=p;
end;

begin
init;
 read(n,m);
 for i:=1 to n do son[i]:=nil;
 for i:=1 to m do
 begin
  read(x,y,k);
  mmake(x,y,k);
 end;
 read(m);
 for i:=1 to m do
 begin
  read(x,y);
  l:=0;r:=100001;
  if not(ok(0)) then
  writeln('-1')
  else
  begin
  while l<r-1 do
  begin
   mid:=(l+r)shr 1;
   if ok(mid) then
    l:=mid
   else
    r:=mid;
  end;
  if ok(r) then writeln(r)
  else
   writeln(l);
 end;
 end;
 oover;
end.

