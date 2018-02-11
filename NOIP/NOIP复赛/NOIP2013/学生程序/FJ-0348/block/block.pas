program block;
var
i,j,t,n,l:longint;
h,a:array[1..10000] of longint;

procedure search;
begin
h[i]:=2*a[i];
j:=0;
repeat

if h[i]>2*a[i] then
	for t:=1 to i do 
		a[i]:=a[i]+1;
	j:=j+1;
	until h[i]=a[i];
	end;
	
		
	begin	
	readln(n);
	i:=n;
	read(a[i]);

assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);
search;
writeln(j);
close(input);
close(output);
end.


