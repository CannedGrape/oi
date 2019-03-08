program block;
var
  n,i,j,k:longint;
  a:array[1..150000] of longint;
procedure find(l,r:longint);
var
  i,j,mid,min:longint;
begin
  min:=maxlongint;mid:=0;
  for i:=l to r do
    if a[i]<min then
    begin
      min:=a[i];
      mid:=i;
    end;
  for i:=l to r do
    dec(a[i],min);
  inc(k,min);
  if mid <>l then
    find(l,mid-1);
  if mid <>r then
    find(mid+1,r);

end;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  read(a[i]);
  k:=0;
  find(1,n);
  writeln(k);
  readln;
  close(input);close(output);
end.
