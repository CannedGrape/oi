var	a,b,c:array[-100..100000] of longint;
	n,p,i,j,max:longint;
procedure qsort(l,r:longint);
var i,j,mid,p:longint;
begin
        i:=l;
        j:=r;
        mid:=b[(l+r) div 2];
        repeat
                while b[i]<mid do inc(i);
                while b[j]>mid do dec(j);
                if i<=j then
                begin
                        p:=b[i];
                        b[i]:=b[j];
                        b[j]:=p;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if l<j then qsort(l,j);
        if i<r then qsort(i,r);
end;

begin
        assign(input,'number.in');
	assign(output,'number.out');
	reset(input);
        rewrite(output);
	max:=-maxlongint;
	read(n,p);
	readln;
	for i:=1 to n do
		read(c[i]);
	a[1]:=c[1];
	for i:=2 to n do
                begin
                for j:=1 to i do
                if c[i]>0 then
                a[i]:=c[j]+a[i]
                else if max<c[i] then
                begin
                max:=c[i];
		c[i]:=a[i]+max;
                end;
                end;
        b[1]:=a[1];
	for i:=2 to n do
		b[i]:=(a[i-1]+b[i-1]) mod p;
        qsort(1,n);
        writeln(b[n]);
	close(input);
	close(output);
end.
