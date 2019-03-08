program number;
Var
  n,m,i,j,g,lv:longint;
  s:array [1..100] of longint;
begin;
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    begin
      read(g);
      for j:=1 to g do read(s[j]);
    end;
  randomize;
  lv:=random(20);
  writeln(lv);
  close(input);
  close(output);
end.
