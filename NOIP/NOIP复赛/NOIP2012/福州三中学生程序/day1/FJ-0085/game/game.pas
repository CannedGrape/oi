const   ff='game';
var 	i,xx,n:longint;
	max,x,s:int64;
        a,b,c:array[0..1010]of longint;
procedure qsort(l,r:longint);
var 	i,j,midx,midy:longint;
begin
if l<r then begin
	i:=l;j:=r;
	midx:=c[(i+j)div 2];
	midy:=a[(i+j)div 2];
	repeat
		while (c[i]<midx)or((c[i]=midx)and(a[i]<midy)) do inc(i);
		while (midx<c[j])or((c[i]=midx)and(midy<a[j])) do dec(j);
		if (i<=j) then begin
			xx:=a[i];a[i]:=a[j];a[j]:=xx;
			xx:=b[i];b[i]:=b[j];b[j]:=xx;
			xx:=c[i];c[i]:=c[j];c[j]:=xx;
			inc(i);dec(j);
			end;
		until i>j;
	qsort(l,j);qsort(i,r);
	end;	
end;


begin
assign(input,ff+'.in');reset(input);
assign(output,ff+'.out');rewrite(output);
read(n);
read(s,xx);
for i:=1 to n do begin
	read(a[i],b[i]);
	c[i]:=a[i]*b[i];
	end;
qsort(1,n);
max:=0;
for i:=1 to n do begin
	x:=s div b[i];
	if max<x then max:=x;
	s:=s*a[i];
	end;
writeln(max);
close(input);close(output);
end.
