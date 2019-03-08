var i,j:longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  read(i,j);
  write(j);
  close(input);
  close(output);
end.