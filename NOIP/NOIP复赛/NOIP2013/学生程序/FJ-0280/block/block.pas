program work;
var a:array[0..111111] of longint;
    i,j,n,m,k,p,q,ans:longint;
procedure init;
begin
 assign(input,'block.in');
 assign(output,'block.out');
 reset(input);
 rewrite(output);
end;
procedure oover;
begin
 close(input);
 close(output);
end;
function dfs(l,r:longint):int64;
var i,j,min:longint;
begin
 if l>r then exit(0);
 dfs:=0;min:=0;
 for i:=l to r do
  if a[i]=0 then
  begin
   for j:=l to i-1 do
    a[j]:=a[j]-min;
   dfs:=dfs(l,i-1)+dfs+min;
   min:=0;
   l:=i+1;
  end
  else
  if (min=0)or(min>a[i]) then
  min:=a[i];
 for j:=l to r do a[j]:=a[j]-min;
 dfs:=dfs+dfs(l,r)+min;
end;
begin
 init;
 read(n);ans:=0;
 for i:=1 to n do read(a[i]);
 a[0]:=0;a[n+1]:=0;
 writeln(dfs(1,n));
 oover;
end.

