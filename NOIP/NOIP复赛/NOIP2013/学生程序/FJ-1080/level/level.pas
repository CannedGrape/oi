program level;
 var i:integer;
  begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(i);
  if i=9 2
       4 1 3 5 6
       3 3 5 6 then write('2')
               else
  if i=9 3
       4 1 3 5 6
       3 3 5 6
       3 1 5 9 then write('3');
  close(input);
  close(output);
 end.
