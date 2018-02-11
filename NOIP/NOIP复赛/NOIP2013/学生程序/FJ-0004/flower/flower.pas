var
  n, i, ans, a, b, h: longint;

procedure stopwith(ans: longint);
begin
  close(input);
  assign(output, 'flower.out');
  rewrite(output);
  writeln(ans);
  close(output);
  halt;
end;

begin
  assign(input, 'flower.in');
  reset(input);
  readln(n);

  if n=1 then stopwith(1);
  read(a, b);
  i:=3;
  while (i<=n) and (a=b) do begin
    read(b);
    inc(i);
  end;
  if a=b then stopwith(1);

  ans:=2;
  for i:=i to n do begin
    read(h);
    if b=h then continue;
    if (b>h) and (a<b) or ((b<h) and (a>b))then inc(ans);
    a:=b;
    b:=h;
  end;
  stopwith(ans);
end.
