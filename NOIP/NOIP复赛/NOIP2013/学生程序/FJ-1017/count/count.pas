var
	x,j,a:integer;
	num:array[1..7]of integer;
	n,i,s:longint;
begin
	assign(input,'count.in');
	assign(output,'count.out');
	reset(input);
	rewrite(output);
	read(n,x);
	s:=0;
	for i:=1 to 7 do num[i]:=0;
	for i:=1 to n do begin
		inc(num[1]);
		for j:=1 to 7 do begin
			if num[j]>9 then begin
				num[j]:=num[j]-10;
				inc(num[j+1]);
			end;
		end;
		a:=0;
		for j:=7 downto 1 do begin
			if num[j]>0 then a:=1;
			if a=1 then begin
				if num[j]=x then inc(s);
			end;
		end;
	end;
	writeln(s);
	close(input);
	close(output);
end.