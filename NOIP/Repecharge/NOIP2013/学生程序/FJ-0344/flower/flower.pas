program flower;
var 
n,i,j,k,ans :longint;
h:array[1..100000] of longint;
begin 
assign(input,'flower.in');
reset(input);
assign(output,'flower.out');
rewrite(output);
readln(n);
ans:=0;
for i:=1 to n do 
  read(h[i]);
for i:=2 to n do  
	if (h[i-1]>h[i]) and (h[i+1]<h[i])  then 
		begin
	       k:=i;
	       repeat
			k:=k+1;
		   until h[k+1]>h[k];
		   for j:=1 to n-i+2 do 
			   begin
			   h[j]:=h[k-1];
		       k:=k+1;
		       end;
		   for j:=n-i+3 to n do
			   h[j]:=0;
		end;
for i:=1 to n do
    if h[i]=0 then break  else ans:=ans+1;
		
writeln(ans);
close(input);
close(output);
end.