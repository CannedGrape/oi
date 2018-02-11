var
	i,j,m,k,l,z:longint;
	a:array[1..1000] of longint;
begin
	assign(input,'level.in');
	assign(output,'level.out');
	reset(input);
	rewrite(output);
	readln(i,j);
	for k:=1 to j do
	begin
		read(l);
		for z:=1 to l do read(a[z]);
		readln;
	end;
	writeln(j);
	close(input);
	close(output);
end.
	
