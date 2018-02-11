var input,output:text;
    i,n,ans:longint;
    a,b,c:array[0..100000]of longint;
procedure search(t:longint);
var i,j,x:longint;
begin
  x:=0;
  for i:=1 to n do
    if c[i]=1 then inc(x);
  if x=n then begin ans:=t-1; exit; end;
  for i:=1 to n do
  if c[i]=0 then begin
    inc(a[i]);
    if a[i]=b[i] then c[i]:=1;
    j:=i+1;
    while (j<=n) and (c[j]=0) do begin
      inc(a[j]);
      if a[j]=b[j] then c[j]:=1;
      inc(j);
    end;
    break;
  end;
  search(t+1);
end;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(input,n);
  for i:=1 to n do
  begin
    read(input,b[i]);
    if b[i]=0 then c[i]:=1;
  end;
  search(1);
  writeln(output,ans);
  close(input);close(output);
end.
