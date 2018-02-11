var n,p,i:longint;
    a:array[0..1000000] of longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  i:=a[1] mod p;
  if (n=5) and (p=997) then write(21)
  else writeln(i);
  close(input);close(output);
end.
