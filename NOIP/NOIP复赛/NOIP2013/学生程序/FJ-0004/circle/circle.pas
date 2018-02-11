var
  n, m, k, x: longint;
  i, j: int64;

begin
  assign(input, 'circle.in');
  reset(input);
  readln(n, m, k, x);
  close(input);
  i:=1;
  j:=10;
  while k>0 do begin
    if odd(k) then i:=i*j mod n;
    j:=j*j mod n;
    k:=k shr 1;
  end;
  assign(output, 'circle.out');
  rewrite(output);
  writeln((i*m+x) mod n);
  close(output);
end.             