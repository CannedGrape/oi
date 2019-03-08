var
  a:array[0..9] of longint;
  i,n,m:longint;
procedure take(x:longint);
begin
  while x>0 do
    begin
      inc(a[x mod 10]);
      x:=x div 10;
    end;
end;
begin
  assign(input,'count.in'); reset(input);
  assign(output,'count.out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
    take(i);
  writeln(a[m]);
  close(input); close(output);
end.
