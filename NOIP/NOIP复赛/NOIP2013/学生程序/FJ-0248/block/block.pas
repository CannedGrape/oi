program block;
var
  ans,i,n:longint;
  h,a,b:array[1..1000000] of longint;
procedure pblock;
var
  i,k,min:longint;
begin
  i:=1;k:=1;

  while i<=n do
  begin
    a[k]:=1;b[k]:=h[i];
    while h[i]<=h[i+1] do  begin
      a[k]:=a[k]+1;

      i:=i+1;
      end;
    k:=k+1;i:=i+1;
  end;
  for i:=1 to k do
    ans:=ans+a[i];
  min:=b[1];
  for i:=1 to k do
    if b[i]<min then min:=b[i];
  for i:=2 to k do
    if b[k]>=min then
      ans:=ans-1;
end;

begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(h[i]);
  ans:=0;
  pblock;
  writeln(ans);
  readln;readln;
  close(input);
  close(output);
end.

