PROGRAM a4(input,output);
var
  n,i,p:longint;
  s,sa,sb:array[1..10000] of longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  read(n);read(p);
  for i:=1 to n do
  read(s[i]);
  close(input);
  sa[1]:=s[1];sb[1]:=s[1];
  for i:=2 to n do
  sa[i]:=sa[i-1]+s[i];
  for i:=2 to n do
  sb[i]:=sb[i-1]+sa[i-1];
  writeln(sb[n] mod p)
  close(output);
end.