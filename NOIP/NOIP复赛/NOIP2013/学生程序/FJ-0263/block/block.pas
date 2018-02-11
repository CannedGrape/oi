uses math;
var n,i,j,k,l,p,s:longint; a:array[1..1000000]of longint;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do
read(a[i]);
for i:=1 to maxvalue(a) do
begin
 for j:=1 to n do
 if a[j]>=i then break;
 for k:=n downto 1 do
 if a[k]>=i then break;
 for l:=j to k do
 if a[l]>=i then p:=1
 else if(p=1)and(a[l]<i)then begin s:=s+1; p:=0;
 end;
 s:=s+1;
end;
writeln(s);
close(input);
close(output);
end.
