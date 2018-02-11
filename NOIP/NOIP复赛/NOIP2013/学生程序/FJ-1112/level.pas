var w,ww,n,m,i,j,a,ans:longint;
   c:array[-100..1000]of boolean;
   b,d:array[0..100000]of longint;
function min(a,b:longint):longint;
  begin
  if a<b then exit(a);exit(b);
  end;
function max(a,b:longint):longint;
  begin
  if a>b then exit(a);exit(b);
  end;
begin
assign(input,'level.in');
assign(output,'level.out');
reset(input);
rewrite(output);
  readln(n,m);
  for i:=1 to n do
    d[i]:=n;

  for i:=1 to m do
    begin
    read(a);
    fillchar(c,sizeof(c),0);
      for j:=1 to a do
      begin
      read(b[j]);
      c[b[j]]:=true;
      end;
    w:=maxlongint;
    ww:=0;
      for j:=b[1] to b[a] do
        if c[j] then w:=min(w,d[j]);
      for j:=b[1] to b[a] do
        if not c[j] and (d[j]>=w) then
          ww:=max(d[j]-w+1,ww);
      for j:=b[1] to b[a] do
        if not c[j] then
          dec(d[j],ww);
    end;

  fillchar(c,sizeof(c),0);
  for i:=1 to n do
    c[d[i]]:=true;
  for i:=0 to n do
    if c[i] then inc(ans);
  writeln(ans);
close(input);
close(output);
end.


