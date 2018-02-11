program level;
var



 begin
   assign(input,'level.in');
   reset(input);
   assign(output,'level.out');
   rewrite(output);





   close(input);
   close(output);
end.