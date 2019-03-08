program day12;
  var a,b,c,e,d:array [1..100000]of int64;
		n,s1,s2,o:int64;
		procedure qsort1(i,l);
		 var r,j,mid ,q:longint;
		 begin
		 r:=i;
		 j:=l;
		 mid :=a[(r+j)div 2];
		 repeat
			 while a[r]< mid do inc(r);
				while a[j]> mid do dec(j);
					if r<j then 
						begin
				         q:=a[r];
						a[r]:=a[j];
					     a[j]:=q;
					    inc (r);
					    dec(j);
					    inc(s1);
					    end ;
			until r>j;
					if i<r then qsort1(i,r);
					if j<l then qsort1(j,l);
		end;
		procedure qsort2(i,l);
		 var r,j,mid ,q:longint;
		 begin
		 r:=i;
		 j:=l;
		 mid :=b[(r+j)div 2];
		 repeat
			 while b[r]< mid do inc(r);
				while b[j]> mid do dec(j);
					if r<j then 
						begin
				         q:=b[r];
						b[r]:=b[j];
					     b[j]:=q;
					    inc (r);
					    dec(j);
					    inc(s2);
					    end ;
			until r>j;
					if i<r then qsort2(i,r);
					if j<l then qsort2(j,l);
						end;
		begin
			assign(input,'match.in');
			reset(input);
			assign(output,'match.out');
			rewrite(output);
			readln(n);
			for o:=1 to n do 
				begin 
			     if o= n then
					 readln(a[o])
				     else 	 
					 read(a[o]);
				 e[o]:=a[o];
				end;
			for o:=1 to n do 
			begin	
					 read(b[o]);
				      d[o]:=b[o];
			end ;
			fillchar(c,sizeof(c),0);
			close(input);
			close(output);
		end.
