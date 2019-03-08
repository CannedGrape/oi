program level;
Var
  n,m,i,j,g,lv:longint;
  s:array [1..100] of longint;
begin;
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    begin
      read(g);
      for j:=1 to g do read(s[j]);
      writeln;
    end;
  randomize;
  lv:=random(20);
  close(input);
  close(output);
end.
