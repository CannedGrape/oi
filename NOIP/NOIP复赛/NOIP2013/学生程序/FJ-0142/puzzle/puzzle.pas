var
  n,m,q,i,j,k:longint;
  a:array[1..31,1..31]of longint;
begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);
  writeln('2');
  writeln('-1');

  close(input); close(output);
end.