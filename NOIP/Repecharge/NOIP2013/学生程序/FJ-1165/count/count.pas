var
  a,b,ans,i,j:longint;
function q(x:longint):longint;
var
  i,ans:longint;
begin
  ans:=1;
  for i:=1 to x do
    ans:=ans*10;
    exit(ans);
end;

function pd(x:longint):longint;
begin
  if x div 10=0 then exit(1);
  if x div 100=0 then exit(2);
  if x div 1000=0 then exit(3);
  if x div 10000=0 then exit(4);
  if x div 100000=0 then exit(5);
  if x div 1000000=0 then exit(6);
  if x div 10000000=0 then exit(7);
end;

begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(a,b);
  for i:=1 to a do
    for j:=1 to pd(i) do
    if ((i mod q(j)) div q(j-1))=b then inc(ans);
  writeln(ans);
  close(input);
  close(output);
end.
