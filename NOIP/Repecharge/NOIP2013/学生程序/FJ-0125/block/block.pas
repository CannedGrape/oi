var n,i,j,x,y:longint;
begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);
 readln(n);
 randomize;
 x:=random(n);
 writeln(x);
close(input);
close(output);
end.
