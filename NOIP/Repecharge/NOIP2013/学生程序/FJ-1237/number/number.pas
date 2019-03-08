var
	a,f:array[0..100000] of longint;
	n,p,i,j,k,x,max:longint;

begin
	assign(input,'number.in');
	assign(output,'number.out');
	reset(input);
	rewrite(output);
	readln(n,p);
	for i:=1 to n do read(a[i]);
        f[1]:=1;
	for i:=2 to n do
	begin
		for j:=1 to i do
                begin
                	x:=0;
			for k:=j to i do
			begin
				x:=x+a[k];
				if x>f[i] then f[i]:=x;
			end;
                end;
	end;
        max:=-1000000;
        for i:=1 to n do
        begin
                for j:=1 to i-1 do f[i]:=f[i]+a[j];
                if f[i]>max then max:=f[i];
        end;
        max:=max mod p;
        writeln(max);
	close(input);
	close(output);
end.