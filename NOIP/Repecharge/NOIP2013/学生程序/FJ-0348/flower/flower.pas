program flower;
var
h:array[1..1000000] of longint;
f: boolean;
i,n,l,m:longint;

procedure dfs(l:longint);
begin
for i:=1 to m do 
if  ((h[2*i] > h[2*i-1])	and ( h[2*i] > h[2*i+1] ))  or (( h[2*i] < h[2*i-1]) and (h[2*I] < h[2*i+1])) then
	f:=true;
if f=false then
	begin
	m:=m-1;
	for i:=2*i to m do 
		h[2*i]:=h[2*i+1] ;
		end;
	if f=true then
		begin
	writeln(n);
	end;
	
	dfs(l-1);

	end;
	

	
	begin
	assign(input,'flower.in');
	reset(input);
	assign(output,'flower.out');
	rewrite(output);
	readln(n);
	readln(h[i]);
	m:=n;
	dfs(l);
	write(m);
	close(input);
	close(output);
	end.
	
	
 
	
