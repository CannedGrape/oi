
{$R-,S-,I-,Q-}

program c2;

const
  MaxN = 20;

var
  N, M, i: Byte;
  ans, s: Longint;
  x: array[1 .. MaxN] of Longint;
  f: array[1 .. 10000] of Byte;
  p: array[1 .. 1229] of Integer;

procedure Get_Prime;
var
  i, j, s: Integer;
begin
  s := 0;
  f[1] := 0;
  for i := 2 to 10000 do f[i] := 1;
  for i := 2 to 10000 do
    if f[i] = 1 then
      begin
        Inc(s);  p[s] := i;
        j := 2 * i;
        while j <= 10000 do begin f[j] := 0; Inc(j, i) end;
      end
end;

procedure Work(S: Longint);
var
  i: Integer;
begin
  if S <= 10000 then Inc(ans, f[S])
  else
    begin
      i := 1;
      while sqr(longint(p[i])) <= S do
        begin
          if S mod p[i] = 0 then Exit;
          Inc(i)
        end;
      Inc(ans)
    end
end;

procedure Search(d, pre: Byte);
var
  i: Byte;
begin
  for i := pre + 1 to N - (M - d) do
    begin
      Inc(S, x[i]);
      if d = M then Work(S)
        else Search(d + 1, i);
      Dec(S, x[i])
    end
end;

begin
  Readln(N, M);
  for i := 1 to N do Read(x[i]);
  ans := 0;  S := 0;
  Get_Prime;
  Search(1, 0);
  Writeln(ans)
end.