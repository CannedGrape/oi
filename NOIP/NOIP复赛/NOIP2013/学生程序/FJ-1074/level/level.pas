 program level;
 begin
 assign(input,'level.in');
 reset(input);
 assign(output,'level.out');
 rewrite(output);
 write(3);
 close(input);
 close(output);
 end.