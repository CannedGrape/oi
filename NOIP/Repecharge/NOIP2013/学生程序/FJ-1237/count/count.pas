var
	n,x,i,j,num:longint;
	a:string;

begin
	assign(input,'count.in');
	assign(output,'count.out');
	reset(input);
	rewrite(output);
	readln(n,x);
	num:=0;
	for i:=1 to n do
	begin
		str(i,a);
		for j:=1 to length(a) do
		if a[j]=chr(x+48) then inc(num);
	end;
	writeln(num);
	close(input);
	close(output);
end.
