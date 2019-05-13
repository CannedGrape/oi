
var
	a,b,c,d,x,tmp:real;  
	ansx,f:array[1..3] of real;
	i,j:integer;

	begin
		readln(a,b,c,d);
		for i:=1 to 3 do
		f[i]:=1e12;
		x:=-100;
		while(x<=100) do
		begin
			tmp:=(d+x*(c+x*(b+x*a)));
			j:=1;
			for i:=2 to 3 do
				if (f[i]>f[j]) then j:=i;
			if (abs(tmp)<f[j]) then
			begin
				f[j]:=abs(tmp);
				ansx[j]:=x;
			end;
			x:=x+0.01;
		end;
		for i:=1 to 3 do
			for j:=i+1 to 3 do
				if (ansx[i]>ansx[j]) then
				begin
					tmp:=ansx[i];
					ansx[i]:=ansx[j];
					ansx[j]:=tmp;
				end;
		writeln(ansx[1]:0:2,' ',ansx[2]:0:2,' ',ansx[3]:0:2);
	end.
