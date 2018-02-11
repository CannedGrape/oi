var m,n:integer;
begin
 assign(input,'level.in');
 assign(output,'level.out');
 reset(input);
 rewrite(output);
 read(m);
 readln(n);
 write(n);
 close(input);
 close(output);
end.
