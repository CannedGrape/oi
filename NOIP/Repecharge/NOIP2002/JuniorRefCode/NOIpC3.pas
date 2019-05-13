
{$R-,S-,I-,Q-}

program c3;

const
  MaxLen = 30;

var
  Len, M: Byte;
  a: array[1 .. MaxLen] of Byte;
  f: array[0 .. 9] of Byte;
  g: array[0 .. 9, 0 .. 9] of Boolean;

procedure Init;
var
  i: Byte;
  St: String;
begin
  Readln(st);
  Len := 0;  M := 0;
  i := 1;
  while st[i] in ['0' .. '9'] do
    begin Inc(Len); a[Len] := Ord(st[i]) - 48; Inc(i) end;
  Repeat
    if st[i] in ['0' .. '9'] then M := M * 10 + Ord(st[i]) - 48;
    Inc(i)
  Until i > Length(st)
end;

procedure Main;
var
  i, j, k: Byte;
begin
  Fillchar(g, Sizeof(g), False);
  for k := 1 to M do
    begin
      Readln(i, j);
      g[i, j] := True
    end;
  for k := 0 to 9 do
    for i := 0 to 9 do
      for j := 0 to 9 do
        g[i, j] := g[i, j] or (g[i, k] and g[k, j]);
  Fillchar(f, Sizeof(f), 0);
  for i := 0 to 9 do g[i, i] := True;
  for i := 0 to 9 do
    for j := 0 to 9 do
      Inc(f[i], Ord(g[i, j]))
end;

procedure Show;
var
  i, j, k, g: Byte;
  ans: Array[1 .. MaxLen] of Byte;
begin
  Fillchar(ans, Sizeof(ans), 0);
  ans[1] := 1;
  for k := 1 to Len do
    begin
      g := 0;
      for i := 1 to MaxLen do
        begin
          ans[i] := ans[i] * f[a[k]] + g;
          g := ans[i] div 10;
          ans[i] := ans[i] mod 10
        end
    end;
  j := MaxLen;
  While ans[j] = 0 do Dec(j);
  for i := j downto 1 do Write(ans[i]);
  Writeln
end;

begin
  Init;
  Main;
  Show
end.