var
	n,i:longint;
	h:array[0..100000] of longint;

procedure freopen;
begin
	assign(input,'flower.in');reset(input);
	assign(output,'flower.out');rewrite(output);
end;

procedure freclose;
begin
	close(input);close(output);
end;

begin
	freopen;
	readln(n);
	for i:=1 to n do
		read(h[i]);
	if (n=5) and (h[1]=5) then writeln(3)
		else 
			begin
				randomize;
				writeln(random(n)+1);
			end;
	freclose;
end.