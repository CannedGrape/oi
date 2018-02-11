var
	s:string;
	i,j,x,n,max:longint;
begin
	assign(input,'count.in');
	assign(output,'count.out');
	reset(input);
	rewrite(output);
	readln(n,x);
	for i:=1 to n do
	begin
		str(i,s);
		for j:=1 to length(s) do
		if (ord(s[j])-ord('0'))=x then inc(max);
	end;
	writeln(max);
	close(input);
	close(output);
end.
	

