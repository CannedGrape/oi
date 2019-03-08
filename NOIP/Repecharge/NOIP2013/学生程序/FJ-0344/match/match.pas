program match;
var
n,i,t,ans:longint;
a,b:array [1..100000] of longint;

begin
assign(input,'match.in');
reset(input);
assign(output,'match.out');
rewrite(output);
ans:=0;
readln(n);
for i:=1 to n do
	read(a[i]);
readln;
for i:=1 to n do
	read(b[i]);
for i:= 1 to n do
	 if (a[i]=b[i+1])  and (a[i]<>b[i]) and (a[i+1]<>b[i+1])   or (a[i+1]=b[i]) then
		begin
		         t:=a[i];  a[i]:=a[i+1];  a[i+1]:=t;     ans:=ans+1;
		end;
for i:=1 to n do
     if  (a[i]=b[i]) and (a[i+1]<>b[i+1])  then
		if (-2*a[i+1]*b[i+1])>(2*b[i]*b[i]-2*a[i+1]*b[i]-2*b[i+1]*b[i] ) then
			begin
			  t:=a[i]; a[i]:=a[i+1] ; a[i+1]:=t;  ans:=ans+1;
            end;
		writeln(ans mod 99999997);
close(input);
close(output);
end.
