program  level;
var
  n,m,j,s,i,p,k,g:longint;
  a,c:array[0..1000000] of longint;

begin
  assign(input,'level.in'); reset(input);
  assign(output,'level.out'); rewrite(output);
  readln(n,m);
  writeln(m);
  close(input); close(output);
end.
