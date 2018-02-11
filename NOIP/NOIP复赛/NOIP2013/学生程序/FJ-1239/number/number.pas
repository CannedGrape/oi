var
	n,p,i,j,max,max1,max3,max2:longint;
	a,b,c:array[1..1000000] of longint;
begin
	assign(input,'number.in');
	assign(output,'number.out');
	reset(input);
	rewrite(output);
	readln(n,p);
	max3:=-maxlongint;
	for i:=1 to n do
	begin
		read(a[i]);
                max2:=-maxlongint;
		max1:=0;
		max:=-maxlongint;
		if i=1 then begin
                        b[i]:=a[i];
                        c[i]:=a[i];
                        max2:=a[i];
                end
		else begin
			for j:=1 to i-1 do
			begin
				if a[j]>max then max:=a[j];
				if a[j]>0 then max1:=max1+a[j];
                                if b[j]+c[j]>max2 then max2:=b[j]+c[j];
			end;
			if max1>0 then b[i]:=max1+a[i]
			else b[i]:=max+a[i];
                        c[i]:=max2;
		end;
                if max3<max2 then max3:=max2;
	end;
	readln;
	writeln(max3 mod p);
	close(input);
	close(output);
end.
				
