const
  maxn = 50000;
var
  i, j, k, n, m, bullshit, fuck, temp: longint;

procedure endwith(i: longint);
begin
  assign(output, 'blockade.out');
  rewrite(output);
  writeln(i);
  close(output);
  halt;
end;

function max(a, b: longint): longint;
begin
  if a>=b then max:=a
  else max:=b
end;

begin
  assign(input, 'blockade.in');
  reset(input);
  readln(n);
  temp:=0;
  bullshit:=0;
  for i:=1 to n-1 do begin
    read(j, k, fuck);
    if (k=1) or (j=1) then inc(temp);
    bullshit:=max(bullshit, fuck);
  end;
  readln(m);
  close(input);
  if m<temp then endwith(-1);
  endwith(bullshit);
end.
