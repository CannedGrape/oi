var
	m,n,i,j,k,l,n_stop,stop,n_begin,n_end:integer;
	max:integer;
	sta:array[1..1000,1..1000]of integer;
	lvl:array[1..1000]of integer;
begin
	assign(input,'level.in');
	assign(output,'level.out');
	reset(input);
	rewrite(output);
	read(n,m);
	for i:=1 to n do lvl[i]:=1;
	for i:=1 to m do begin
		n_begin:=0;
		n_end:=0;
		read(n_stop);
		for j:=1 to n_stop do begin
			read(stop);
			sta[i,stop]:=1;
			if j=1 then n_begin:=stop;
			if j=n_stop then n_end:=stop;
		end;
		for j:=1 to n do begin
			if j<n_begin then sta[i,j]:=-1;
			if j>n_end then sta[i,j]:=-1;
		end;
	end;
	for i:=1 to n do begin
		for j:=1 to m do begin
			for k:=1 to n do begin
				if sta[j,k]=1 then begin
					for l:=1 to n do begin
						if sta[j,l]=0 then begin
							if lvl[k]<=lvl[l] then lvl[k]:=lvl[l]+1;
						end;
					end;
				end;
			end;
		end;
	end;
	max:=0;
	for i:=1 to n do begin
		if lvl[i]>max then max:=lvl[i];
	end;
	writeln(max);
	close(input);
	close(output);
end.