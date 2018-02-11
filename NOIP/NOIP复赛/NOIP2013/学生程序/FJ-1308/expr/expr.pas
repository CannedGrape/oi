program expr;
var a,x,s:longint;
    y:char;
begin
assign(input,'expr.in');
reset(input);
assign(output,'expr.out');
rewrite(output);
read(x);
read(y);
read(a);
close(input);
case y of
'+':s:=x+a;
'*':s:=x*a;
end;
write(s);
close(output);
end.
