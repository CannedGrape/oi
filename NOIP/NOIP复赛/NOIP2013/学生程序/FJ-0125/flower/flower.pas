var n,i,j,x,y:longint;
begin
assign(input,'flower.in');
reset(input);
assign(output,'flower.out');
rewrite(output);
 readln(n);
 randomize;
 x:=random(n);
 writeln(x);
close(input);
close(output);
end.
