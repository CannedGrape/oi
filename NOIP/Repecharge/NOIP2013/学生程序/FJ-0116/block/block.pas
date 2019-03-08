var
  i,j,n,total:longint;
  a,b,c:array[0..100000] of longint;
begin
  assign(input,'block.in'); reset(input);
  assign(output,'block.out'); rewrite(output);
  readln(n);j:=1;
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i]<a[i-1] then
    begin
    b[j]:=a[i-1];c[j]:=a[i];
    inc(j);
    end;
  end;
  inc(j);b[j]:=a[n];
  for i:=1 to j do
    total:=total+b[i]-c[i];
  writeln(total);
  close(input); close(output);
end.
