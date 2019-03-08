program count;
var
x,i,ans,n,j:longint;



function calc(n:longint):longint;

begin
calc:=0;
repeat
	if n mod 10=x then inc(calc);
	n:=n div 10;
until  n=0;
end;
	
	
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);

readln(n,x);
ans:=0;
for i:=1 to n do ans:=ans+calc(i);
{ans:=(n mod 100 div 10);}
writeln(ans);

close(input);
close(output);
end.