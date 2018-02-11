
{$R-,S-,I-,Q-,N+}

program c4;

const
  dx: array[1 .. 8] of Shortint = (-2, -1, 1, 2, 2, 1, -1, -2);
  dy: array[1 .. 8] of Shortint = (1, 2, 2, 1, -1, -2, -2, -1);

var
  n, m, x, y, i, j: Byte;
  g: array[0 .. 20, 0 .. 20] of Byte;
  f: array[0 .. 20, 0 .. 20] of Comp;

begin
  Readln(n, m, x, y);
  Fillchar(g, Sizeof(g), 0);
  g[x, y] := 1;
  for i := 1 to 8 do
    if (x + dx[i] >= 0) and (x + dx[i] <= n) and
     (y + dy[i] >= 0) and (y + dy[i] <= m) then
       g[x + dx[i], y + dy[i]] := 1;
  f[0, 0] := 1;
  for i := 1 to n do
    if g[i, 0] = 0 then f[i, 0] := f[i - 1, 0];
  for i := 1 to m do
    if g[0, i] = 0 then f[0, i] := f[0, i - 1];
  for i := 1 to n do
    for j := 1 to m do
      if g[i, j] = 0 then f[i, j] := f[i - 1, j] + f[i, j - 1];
  Writeln(f[n, m]: 0: 0)
end.
