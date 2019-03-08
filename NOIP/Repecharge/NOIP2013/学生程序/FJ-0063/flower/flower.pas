type
	v=longint;
var
	t,n,i:v;
	a:array[0..100001]of v;
begin
	assign(input,'flower.in');
	assign(output,'flower.out');
	reset(input);
	rewrite(output);
	read(n);
	for i:=1 to n do
		read(a[i]);
	if n=1 then t:=1
	else t:=2;
	for i:=2 to n-1 do
		if((a[i]>a[i-1])and(a[i]>a[i+1]))or((a[i]<a[i-1])and(a[i]<a[i+1]))then t:=t+1;
	write(t);
	close(input);
	close(output);
end.