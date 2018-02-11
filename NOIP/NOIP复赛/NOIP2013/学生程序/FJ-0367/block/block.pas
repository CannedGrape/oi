var
  n,i,s:longint;
  h:array[0..100000]of longint;
procedure qsort(l,r:longint);
var mid,x,i,j:longint;
begin
  i:=l; j:=r;
  mid:=h[(i+j)div 2];
  repeat
    while h[i]<mid do inc(i);
    while h[j]>mid do dec(j);
    if i<=j then
    begin
      x:=h[i]; h[i]:=h[j]; h[j]:=x;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(h[i]);
  end;
  qsort(1,n);
  s:=h[n]+h[1];
  writeln(s);
  close(input); close(output);
end.
