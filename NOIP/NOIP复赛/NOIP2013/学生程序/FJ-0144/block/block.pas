var
  n,i,k,max,mm,l,j,min,ww,q:longint;
  a,b:array[1..10000] of longint;
  c:array[1..10000] of boolean;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);max:=-maxlongint;ww:=-maxlongint;min:=maxlongint;
  for i:=1 to n do begin
  read(a[i]);
  if a[i]>max then begin max:=a[i];l:=i; end;
  end;
  for i:=1 to n do if a[i]<min then begin min:=a[i];j:=i; end;
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),false);
  k:=0;
  mm:=-maxlongint;
  repeat
  for i:=1 to n do
  begin
    if b[i]=a[i] then
    c[i]:=true;
    if c[i]=false then begin inc(b[i]);if b[i]>mm then mm:=b[i];end;
  end;
  inc(k);
  until mm=max;
  if l<j then
  begin
  for q:=j to n do
  if a[q]>ww then ww:=a[q];
  end;
  if l>j then begin
  for q:=1 to j do
  if a[q]>ww then ww:=a[q];end;
  writeln(k+ww-min);
  close(input);close(output);
end.
