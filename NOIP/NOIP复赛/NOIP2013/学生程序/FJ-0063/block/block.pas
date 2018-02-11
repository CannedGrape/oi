type
	v=longint;
var
	n,i:v;
	t:int64;
	a:array[-1..100002]of v;
begin
	t:=0;
	assign(input,'block.in');
	assign(output,'block.out');
	reset(input);
	rewrite(output);
	read(n);
	for i:=1 to n do
		read(a[i]);
	for i:=n downto 2 do
		a[i]:=a[i]-a[i-1];
	for i:=1 to n do
		if a[i]>0 then t:=t+a[i];
	write(t);
	close(input);
	close(output);
end.