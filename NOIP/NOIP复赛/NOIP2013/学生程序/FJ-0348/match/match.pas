program match;
var
a:array[1..100000] of longint;
b:array[1..100000] of longint;
i,j,mid,p,n:longint;
 sum:longint;
begin 
assign(input,'match.in');
 reset(input);
 assign(output,'match.out');
 rewrite(output);
 readln(n);
 for i:=1 to n do 
	 read(a[i]);
     read(b[i]);
 for i:=1 to n do 	
 sum:=(a[i]-b[i])*(a[i]-b[i]);
begin
 if sum=0 then write(1);
if sum<>0 then write(2);
	 end;
 close(input);
 close(output);
 
end.
 
 
 
 
          