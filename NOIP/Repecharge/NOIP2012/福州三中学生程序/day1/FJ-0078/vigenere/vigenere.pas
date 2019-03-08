Var
  k,s:ansistring;
  i:longint;
Procedure work(x:longint);
var
  ordk,ords:longint;
begin
  ordk:=ord(k[x]);
  if (ordk>=65) and (ordk<=90) then ordk:=ordk-65;
  if (ordk>=97) and (ordk<=122) then ordk:=ordk-97;
  ords:=ord(s[x]);
  if (ords>=65) and (ords<=90) then
  begin
    ords:=ords-65;
    ords:=(ords-ordk+260) mod 26;
    s[x]:=chr(65+ords);
  end;
  if (ords>=97) and (ords<=122) then
  begin
    ords:=ords-97;
    ords:=(ords-ordk+260) mod 26;
    s[x]:=chr(97+ords);
  end;
end;
Begin
  assign(input,'vigenere.in');
  assign(output,'vigenere.out');
  reset(input);
  rewrite(output);
  readln(k);
  readln(s);
  for i:=1 to 10 do k:=k+k;
  for i:=1 to length(s) do
    work(i);
  writeln(s);
  close(input);
  close(output);
End.