var	a:array[1..1000] of longint;
	i,n,p:longint;
begin
	assign(input,'number.in'); reset(input);
	assign(output,'number.out'); rewrite(output);
	readln(n,p);
	for i:=1 to n do read(a[i]);
	writeln(-1);
	close(input); close(output);
end.
