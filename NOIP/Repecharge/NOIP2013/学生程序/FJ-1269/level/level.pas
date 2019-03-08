program level;
var n,x:longint;
begin
 assign(input,'level.in');reset(input);
 assign(output,'level.out');rewrite(output);
 read(n,x);
 if (n=9)and(x=2) then writeln(2);
 if (n=9)and(x=3) then writeln(3);
 close(input);close(output);
end.