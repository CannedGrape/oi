const
  b:array [1..6] of longint=(2,21,301,4001,50001,600001);
  a:array [1..6] of longint=(10,100,1000,10000,100000,1000000);
  c:array [1..6] of longint=(1,11,192,2893,38894,488895);
var
  n,x,i,ans,ws:longint;
  zh:ansistring;
function pd(s:longint):longint;
var
  i:longint;
  zf,f:ansistring;
begin
  str(s,zf);
  str(x,f);
  pd:=0;
  for i:=1 to length(zf) do
    if zf[i]=f then inc(pd);
end;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  if n>=10 then
    begin
      str(n,zh);
      if x=0 then
        ans:=c[length(zh)-1]
      else
        ans:=b[length(zh)-1];
      for i:=a[length(zh)-1]+1 to n do
        inc(ans,pd(i));
    end
  else
    begin
      if x<=n then
        ans:=1
      else
        ans:=0;
      if x=0 then
        ans:=0;
    end;
  writeln(ans);
  close(input);
  close(output);
end.
