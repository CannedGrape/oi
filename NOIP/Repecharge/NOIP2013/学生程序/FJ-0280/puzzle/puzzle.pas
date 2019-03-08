program work;
const dx:array[1..4] of longint=(1,0,0,-1);
     dy:array[1..4] of longint=(0,1,-1,0);
var i,j,n,m,x,y,go1,go2,l1,r1,k1,k2,p,num:longint;
    limit:longint;
    flag:boolean;
    map:array[0..50,0..50] of boolean;
procedure init;
begin
 assign(input,'puzzle.in');
 assign(output,'puzzle.out');
 reset(input);
 rewrite(output);
end;
procedure oover;
begin
 close(input);
 close(output);
end;
procedure ook;
begin
 if(l1=go1)and(r1=go2) then
  begin
   num:=limit;
   flag:=true;
  end;
end;
procedure dfs(k,x,y:longint);
var l,r,i:longint;
begin
 if k>limit then begin ook;exit;end;
 for i:=1 to 4 do
 begin
  l:=dx[i]+x;r:=dy[i]+y;
  if (map[l,r]) then
  begin
   if (l=l1)and(r=r1) then
    begin
     l1:=x;r1:=y;
    end;
   dfs(k+1,l,r);
  end;
 end;
end;
begin
 init;
 fillchar(map,sizeof(map),false);
 read(n,m,p);
 for i:=1 to n do
  for j:=1 to m do
  begin
   read(x);
   if x=1 then
   map[i,j]:=true;
  end;
 for i:=1 to p do
 begin
  read(k1,k2,x,y,go1,go2);
  if (x=go1)and(y=go2) then
   begin
    writeln('0');
    continue;
   end;
  flag:=false;
  for limit:=1 to 18 do
  begin
   l1:=x;r1:=y;
   if flag then break;
   dfs(1,k1,k2);
  end;
  if flag then writeln(num) else writeln('-1');
 end;
oover;
end.
