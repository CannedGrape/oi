var
	a:array[0..1001] of longint;
	n,m,k,x,i,j,num:longint;

begin
	assign(input,'level.in');
	assign(output,'level.out');
	reset(input);
	rewrite(output);
	readln(n,m);
	for i:=1 to m do
	begin
		read(k);
		for j:=1 to k do
		begin
			read(x);
			inc(a[x]);
		end;
		readln;
	end;
	for i:=1 to n do if a[i]>0 then inc(num);
	num:=num-2;
	writeln(num);
	close(input);
	close(output);
end.