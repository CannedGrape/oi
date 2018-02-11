var
	n,p,i,j,k,m,t,t_max,f,f_max,s:longint;
	num,tz,fs:array[1..1000000]of longint;
begin
	assign(input,'number.in');
	assign(output,'number.out');
	reset(input);
	rewrite(output);
	read(n,p);
	s:=-2147483648;
	for i:=1 to n do begin
		read(num[i]);
		t_max:=num[i];
		for j:=1 to i do begin
			for k:=j to i do begin
				t:=0;
				for m:=j to k do begin
					t:=t+num[m];
				end;
				if t>t_max then t_max:=t;
			end;
		end;
		tz[i]:=t_max;
		f_max:=tz[1];
		if i>1 then begin
			for j:=1 to i-1 do begin
				f:=fs[j]+tz[j];
				if f>f_max then f_max:=f;
			end;
		end;
		fs[i]:=f_max;
		if fs[i]>s then s:=fs[i];
	end;
	writeln(f_max mod p);
	close(input);
	close(output);
end.