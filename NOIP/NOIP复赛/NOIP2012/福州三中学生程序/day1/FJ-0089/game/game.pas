program xxx;
var a:array [0..1000,1..2] of longint;
 c:array [0..1000] of real;
 o1:real;
 best,total,l,r,o2,up,down,i,j,k,n,m:longint;
 f:array [0..1000] of boolean;
procedure dfs(x,max:longint);
var i:longint;
begin
 if x>n then
 begin if best>max then best:=max; end
 else
 for i:=1 to n do
  if f[i] then
   begin
    if max<(total) div a[i,2] then
     max:=(total) div a[i,2];
    if max>best then exit;
    f[i]:=false; total:=total*a[i,1];
    dfs(x+1,max);
    f[i]:=true; total:=total div a[i,1];
   end;
end;
begin
 assign(input,'game.in');
 assign(output,'game.out');
 reset(input); rewrite(output);
 read(n);
 fillchar(f,sizeof(f),true);
 for i:=0 to n do
  begin
   read(a[i,1],a[i,2]);
   c[i]:=a[i,1]/a[i,2];
  end;
 total:=a[0,1];
 best:=10000000;
 dfs(1,0);
 write(best);
 close(input); close(output);
end.

