var
  k,l,m:longint;
  a:array[1..3]of longint;
begin
  assign(input,'expr.in');assign(output,'expr.out');
  reset(input);rewrite(output);
  randomize;
  k:=9999;  l:=9; m:=2;
  a[1]:=random(k);
  a[2]:=random(l+2);
  writeln(a[random(m)+1]);
  close(input);close(output);
end.
