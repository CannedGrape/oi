program circle;
var n,m,k,i,j,step,x,temp:longint;
      time:int64;
	  a:array[0..100000000]of longint;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
reset(output);
rewrite(output);

time:=1;
readln(n,m,k,x);
for i:=0 to n-1 do
	a[i]:=i;
for i:=1 to k do;
	time:=time*10;
step:=(m*time) mod n;
for i:=1 to step do
	begin
        temp:=a[n-1];
		for j:=n-1 downto 1 do;
		a[j]:=a[j-1];
		a[0]:=temp;
	end;

write(a[x]);
close(input);
close(output);


end.
