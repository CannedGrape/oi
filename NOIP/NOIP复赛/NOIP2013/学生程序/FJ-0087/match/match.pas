type arr=array[0..1000000] of longint;
var a,b:arr;
      n,i:longint;
	  tot:int64;

procedure freopen;
begin
	assign(input,'match.in');reset(input);
	assign(output,'match.out');rewrite(output);
end;

procedure freclose;
begin
	close(input);close(output);
end;
procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
	i:=l;j:=r;x:=a[(l+r) div 2];
	repeat
		while a[i]<x do inc(i);
		while x<a[j] do dec(j);
		if not(i>j) then
			begin
				y:=a[i];a[i]:=a[j];a[j]:=y;
				inc(i);j:=j-1;
             end;
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
end;        
begin
	freopen;
	readln(n);
	for i:=1 to n do
		read(a[i]);
	for i:=1 to n do
		read(b[i]);
	sort(1,n);
	tot:=0;
	for i:=1 to n do
		if a[i]<>b[i] then 
			begin
		        inc(tot);
				tot:=tot mod 99999997;
			end;
	writeln(tot);
	freclose;
end.
