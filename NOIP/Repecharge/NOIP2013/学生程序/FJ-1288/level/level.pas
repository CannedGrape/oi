var
n,m:longint;


begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);


  read(n,m);
  writeln(m);


   close(input);
  close(output);
end.
