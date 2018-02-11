var n,i,j,t:longint;
    ans:int64;
    a:array[0..100001] of longint;

function tail(l,r:longint):longint;
var i:longint;
    bo:boolean;
begin
  bo:=false;
  for i:=l to r do
    if a[i]=0 then
    begin
      bo:=true;
      exit(i-1);
    end;
  if bo=false then exit(0);
end;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  ans:=0;i:=1;
  while i<=n do
  begin
    if a[i]>0 then
    begin
      t:=tail(i,n);
      if t<>0 then
        for j:=i to t do dec(a[j])
      else for j:=i to n do dec(a[j]);
      inc(ans);
    end;
    if a[i]=0 then inc(i);
  end;
  writeln(ans);
  close(input);close(output);
end.
