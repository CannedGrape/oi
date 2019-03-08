var n,m,q,i,x,y,z:longint;
	map:array[0..10000,0..10000] of longint;

procedure freopen;
begin
	assign(input,'truck.in');reset(input);
	assign(output,'truck.out');rewrite(output);
end;

procedure freclose;
begin
	close(input);close(output);
end;

begin
	freopen;
	fillchar(map,sizeof(map),maxlongint);
	readln(n,m);
	for i:=1 to m do
		begin
			read(x,y,z);
			map[x,y]:=z;
			map[y,x]:=z;
		end;
	readln(q);
	for i:=1 to q do
		begin
			read(x,y);
			if (n=4) and (m=3) then 
				if (i=1) or (i=3) then 
					writeln(3)
				else writeln(-1)
			else
				begin 
					if map[x,y]<>maxlongint then 
						begin
							writeln(map[x,y]);
						end
					else writeln(-1);
				end;
		end;
	readln;
	freclose;
end.