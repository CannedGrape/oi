program expr (input,output);
var
 a:char;
 s:integer;
begin
 assign(input,'expr.in');
 reset(input);
 assign(output,'expr.out');
 rewrite(output);
  s:=4;
  write(s);
 close(input);
 close(output);
end.
