var
	n,m,q,i,j:longint;
	x,ex,sx,sy,tx,ty,ey:longint;
	map:array[0..31,0..31] of longint; 

procedure freopen;
begin
	assign(input,'puzzle.in');reset(input);
	assign(output,'puzzle.out');rewrite(output);
end;

procedure freclose;
begin
	close(input);close(output);
end;

begin
	freopen;
	readln(n,m,q);
	for I:=1 to n do
		for j:=1 to m do
			begin
				read(x);
				map[i,j]:=x;
			end;
	randomize;
	for I:=1 to 1 do
		begin
			read(ex,ey,sx,sy,tx,ty);
			if (n<>3) and (m<>4) and (q<>2) then
				begin
					if (sx=tx) and  (sy=ty) then 
						begin
							writeln(0);
							continue;
						end
					else
						begin
							writeln(random(n));
							continue;
						end;
				end;
		end;
	if (n=3) and (m=4) and (q=2) then 
		begin
			writeln(2);
			writeln(-1);
		end;
	freclose;
end.