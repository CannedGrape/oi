program ex;
var ans,i,j,m,n,k:longint;
    a:array[0..100001] of longint;
    nearmax,nearmin:array[0..100001] of longint;
    dp1,dp2:array[0..100001] of longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a) else exit(b);
end;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
   read(a[i]);
  nearmax[0]:=0;
  nearmin[0]:=0;
  for i:=1 to n do
   begin
    if a[i]<a[i-1] then
     nearmax[i]:=i-1
    else
     nearmax[i]:=nearmax[i-1];
    if a[i]>a[i-1] then
     nearmin[i]:=i-1
    else
     nearmin[i]:=nearmin[i-1];
   end;
  dp1[n]:=1;
  dp2[n]:=1;
  ans:=0;
  for i:=n downto 1 do
   begin
    if (dp1[i] mod 2 =0) then
     j:=nearmin[i]
    else
     j:=nearmax[i];
    dp1[j]:=max(dp1[j],dp1[i]+1);

    if (dp2[i] mod 2=0) then
     j:=nearmax[i]
    else
     j:=nearmin[i];
    dp2[j]:=max(dp2[j],dp2[i]+1);
    ans:=max(ans,max(dp1[i],dp2[i]));
   end;
  writeln(ans);
  close(input);
  close(output);
end.





