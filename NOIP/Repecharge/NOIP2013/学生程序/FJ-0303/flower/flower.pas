program flower;
var
  dp:array[0..100500,1..2]of longint;
  a:array[1..100500]of longint;
  i,j,k,n,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a)
  else exit(b);
end;
begin
  assign(input,'flower.in');
  reset(input);
  read(n);
  dp[1,1]:=1;dp[1,2]:=1;ans:=1;
  for i:=1 to n do
  read(a[i]);
  for i:=2 to n do
  begin
    for j:=i-1 downto 1 do
    begin
     if a[i]>a[j]then
     dp[i,1]:=max(dp[i,1],dp[j,2]+1);
     if a[i]<a[j]then
     dp[i,2]:=max(dp[i,2],dp[j,1]+1);
    end;
    ans:=max(max(dp[i,2],dp[i,1]),ans);
  end;
  assign(output,'flower.out');
  rewrite(output);
  writeln(ans);
  close(input);close(output);
end.
