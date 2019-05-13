
{$N+}

program c1;

var
  K: Byte;
  n: Longint;
  Sn: Extended;

begin
  Readln(K);
  Sn := 0; n := 0;
  Repeat
    Inc(n);
    Sn := Sn + 1 / n;
  Until Sn > k;
  Writeln(n);
end.