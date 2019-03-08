var
	s,m,l:string;
	i,j,k,w,max,b,u,n,z:longint;
	a:array[1..100000] of longint;
begin
	assign(input,'expr.in');
	assign(output,'expr.out');
	reset(input);
	rewrite(output);
	readln(s);
	j:=0;
        	i:=0;
                z:=10;
        	n:=length(s);
	while u<>n do
	begin
            	inc(u);
           		inc(i);
            	b:=0;
		if s[i]='+' then begin
			inc(j);
			m:=copy(s,1,i-1);
			val(m,a[j]);
			a[j]:=a[j] mod 10000;
			delete(s,1,i);
                        	i:=0;
		end;
		if s[i]='*'  then
		begin
			inc(j);
			m:=copy(s,1,i-1);
			val(m,a[j]);
			delete(s,1,i);
                        	i:=0;
			for k:=i to n do
			if (s[k]='*')or(s[k]='+') then
			begin
				m:=copy(s,1,k-1);
				val(m,w);
                                delete(m,1,length(m));
				str((a[j]*w),m);
				j:=j-1;
				delete(s,1,k-1);
                                		i:=0;
                                		z:=5;
				break;
			end else z:=0;
			if z=5 then insert(m,s,1);
		end;
	end;
	val(s,a[j+1]);
        	if z=0 then begin a[j]:=a[j]*a[j+1]; dec(j); end;
	for i:=1 to j+1 do max:=(max+a[i]) mod 10000;
	writeln(max);
	close(input);
	close(output);
end.









