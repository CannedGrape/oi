var	a:array[1..7] of integer;
	n,x,i:longint;
        ans:int64;

procedure	c1(k:longint);
begin
	a[1]:=k mod 10;
	if a[1]=x then inc(ans);
end;

procedure	c2(k:longint);
begin
	a[1]:=k div 10;
	a[2]:=k mod 10;
	if a[1]=x then inc(ans);
	if a[2]=x then inc(ans);
end;

procedure	c3(k:longint);
begin
	a[1]:=k div 100;
	a[2]:=(k div 10) mod 10;
	a[3]:=k mod 10;
	if a[1]=x then inc(ans);
	if a[2]=x then inc(ans);
	if a[3]=x then inc(ans);
end;

procedure	c4(k:longint);
begin
	a[1]:=k div 1000;
	a[2]:=(k div 100) mod 10;
	a[3]:=(k div 10) mod 10;
	a[4]:=k mod 10;
	if a[1]=x then inc(ans);
	if a[2]=x then inc(ans);
	if a[3]=x then inc(ans);
	if a[4]=x then inc(ans);
end;

procedure	c5(k:longint);
begin
	a[1]:=k div 10000;
	a[2]:=(k div 1000) mod 10;
	a[3]:=(k div 100) mod 10;
	a[4]:=(k div 10) mod 10;
	a[5]:=k mod 10;
	if a[1]=x then inc(ans);
	if a[2]=x then inc(ans);
	if a[3]=x then inc(ans);
	if a[4]=x then inc(ans);
	if a[5]=x then inc(ans);
end;

procedure	c6(k:longint);
begin
	a[1]:=k div 100000;
	a[2]:=(k div 10000) mod 10;
	a[3]:=(k div 1000) mod 10;
	a[4]:=(k div 100) mod 10;
	a[5]:=(k div 10) mod 10;
	a[6]:=k mod 10;
	if a[1]=x then inc(ans);
	if a[2]=x then inc(ans);
	if a[3]=x then inc(ans);
	if a[4]=x then inc(ans);
	if a[5]=x then inc(ans);
	if a[6]=x then inc(ans);
end;

procedure	c7(k:longint);
begin
	a[1]:=k div 1000000;
	a[2]:=(k div 100000) mod 10;
	a[3]:=(k div 10000) mod 10;
	a[4]:=(k div 1000) mod 10;
	a[5]:=(k div 100) mod 10;
	a[6]:=(k div 10) mod 10;
	a[7]:=k mod 10;
	if a[1]=x then inc(ans);
	if a[2]=x then inc(ans);
	if a[3]=x then inc(ans);
	if a[4]=x then inc(ans);
	if a[5]=x then inc(ans);
	if a[6]=x then inc(ans);
	if a[7]=x then inc(ans);
end;

begin
	assign(input,'count.in'); reset(input);
	assign(output,'count.out'); rewrite(output);
	read(n); read(x);
	ans:=0;
	for i:=1 to n do
	  begin
	    if i-10<0 then c1(i);
	    if (i-10>=0) and (i-100<0) then c2(i);
	    if (i-100>=0) and (i-1000<0) then c3(i);
	    if (i-1000>=0) and (i-10000<0) then c4(i);
	    if (i-10000>=0) and (i-100000<0) then c5(i);
	    if (i-100000>=0) and (i-1000000<0) then c6(i);
	    if i=1000000 then c7(i);
	  end;
	writeln(ans);
	close(input); close(output);
end.
