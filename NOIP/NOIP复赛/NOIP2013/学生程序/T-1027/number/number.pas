var
 a,b,c:array[-1..1000000] of longint;
 m,n,i,j,k,l,o:longint;
begin
 assign(input,'number.in'); reset(input);
 assign(output,'number.out'); rewrite(output);
 read(n,m); readln;
 l:=-1000000;
 for i:=1 to n do
 b[1]:=a[1]; c[1]:=b[1];
 for i:=2 to n do
 begin
 k:=i;
 o:=i;
 while k>0 do
 begin
 if a[k]>0 then
 b[o]:=b[o]+a[k];
 dec(k);
 end;
 end;
 for i:=2 to n do
 c[i]:=c[i-1]+b[i-1];
 for i:=1 to n do
 if l<c[i] then l:=c[i];
 l:=l mod m;
 writeln(l);
 close(input);
 close(output);
end.

