var n,i,j,k,t,l,ans,top:longint;
    f,a:array[0..100001] of longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;
begin
  assign(input,'block.in'); reset(input);
  assign(output,'block.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  top:=maxlongint;
  for i:=1 to n+1 do
  begin
    if a[i]>=a[i-1] then
    begin
      top:=min(top,a[i]);
      f[i]:=f[i-1]+a[i]-a[i-1];
    end
    else
    begin
      top:=min(top,a[i]);
      f[i]:=f[i-1];
    end;
  end;
  writeln(f[n]);
  close(input); close(output);
end.

