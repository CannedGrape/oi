{ NOI 2002 Day 2 Problem 3 Robot.pas   by Macsy }
const
  finp = 'robot.in';
  fout = 'robot.ans';
  mask = 1000000;

var
  k, i, q, m, a, b, protoss, terran, zerg: longint;
  p: array[byte] of longint;

function f(k: longint): longint;
begin
  f := (k mod mask + mask) mod mask;
end;

begin
  assign(input, finp);
  reset(input);
  readln(k);
  m := 1;
  for i := 1 to k do
  begin
    read(p[i]);
    m := f(m * p[i]);
  end;
  close(input);
  a := 1;
  b := 1;
  for i := 1 to k do
  begin
    q := 1;
    while p[q] <> p[i] do
      q := q + 1;
    if (q = i) and (p[q] <> 2) then
    begin
      a := f(a * p[i]);
      b := f(b * (2 - p[i]));
    end;
  end;
  protoss := f((a - b) div 2);
  terran := f(a - protoss - 1);
  zerg := f(m - 1 - terran - protoss);
  assign(output, fout);
  rewrite(output);
  writeln(terran mod 10000);
  writeln(protoss mod 10000);
  writeln(zerg mod 10000);
  close(output);
end.
