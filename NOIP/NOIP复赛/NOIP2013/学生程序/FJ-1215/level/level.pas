Program HJF_level;
var
   a:longint;
begin
   assign(input,'level.in');   reset(input);
   assign(output,'level.out');   rewrite(output);
   readln(a,a);
   writeln(a);
   close(input);
   close(output);
end.
