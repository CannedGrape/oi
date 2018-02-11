var
mh,ans,m,i,p,n:longint;
fs,dp,data:array[0..1000000] of longint;

function max(a,b:longint):longint;
begin
if a>b then max:=a else max:=b;
end;

begin
assign(input,'number.in'); reset(input);
assign(output,'number.out'); rewrite(output);
readln(n,p);
for i:=1 to n do
read(data[i]);
dp[1]:=data[1];
for i:=2 to n do
dp[i]:=max(dp[i-1]+data[i],data[i]);
fs[1]:=dp[1];
fs[2]:=fs[1]+dp[1];
m:=max(dp[1],dp[2]);
for i:=3 to n do
begin fs[i]:=max(fs[i-1],m+fs[i-1]); m:=max(m,dp[i]); end;
ans:=max(fs[1],fs[n]);
writeln(ans mod p);
close(input);
close(output);
end.
