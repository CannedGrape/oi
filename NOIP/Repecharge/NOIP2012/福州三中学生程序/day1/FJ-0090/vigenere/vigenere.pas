var
  c, k: array[1..1000] of char;
  i, l, n: integer;
  ch: char;

function unlock(c, k: char): char;
begin
  if ('A'<=c) and (c<='Z') then
    unlock:=chr((ord(c)-ord(k)+26) mod 26+65)
  else
    unlock:=chr((ord(c)-32-ord(k)+26) mod 26+97)
end;

begin
  assign(input, 'vigenere.in');
  reset(input);

  n:=0;
  l:=0;
  read(ch);
  while (ch<>chr(13)) and (ch<>chr(10)) do begin
    inc(n);
    k[n]:=ch;
    read(ch);
  end;
  read(ch);
  if ch=chr(10) then read(ch);

  while (ch<>chr(13)) and (ch<>chr(10)) do begin
    inc(l);
    c[l]:=ch;
    read(ch);
  end;
  readln;
close(input);

  for i:=1 to n do
    k[i]:=upcase(k[i]);

  for i:=1 to l do
    c[i]:=unlock(c[i], k[(i-1) mod n+1]);

assign(output, 'vigenere.out');
rewrite(output);
  for i:=1 to l do write(c[i]);
  writeln;
close(output);
end.
