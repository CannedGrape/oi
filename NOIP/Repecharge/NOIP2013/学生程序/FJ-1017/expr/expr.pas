var
	str:ansistring;
	l,i,j,q,s:longint;
	num:array[1..100001]of longint;
	k:array[1..100000]of integer;
begin
	assign(input,'expr.in');
	assign(output,'expr.out');
	reset(input);
	rewrite(output);
	read(str);
	l:=length(str);
	j:=1;
	q:=0;
	for i:=1 to 100001 do num[i]:=0;
	for i:=1 to l do begin
		if str[i]='+' then begin
			inc(q);
			inc(j);
			k[q]:=1;
		end else if str[i]='*' then begin
			inc(q);
			inc(j);
			k[q]:=2;
		end else begin
			num[j]:=num[j]*10+ord(str[i])-ord('0');
		end;
	end;
	for i:=1 to q do begin
		if k[i]=2 then begin
			num[i+1]:=(num[i] mod 10000)*(num[i+1] mod 10000);
			num[i]:=0;
		end;
	end;
	s:=0;
	for i:=1 to j do begin
		s:=s+(num[i] mod 10000);
		s:=s mod 10000;
	end;
	writeln(s);
	close(input);
	close(output);
end.