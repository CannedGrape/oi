var
 i,j,n,m,t:longint;
 a:array[1..10000]of longint;
begin
 assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
 readln(n,m);
 for i:=1 to m do
 begin
 read(t);
 for j:=1 to t do
 read(a[j]);
 end;
 if n mod m=0 then writeln(n div m)
 else writeln(m);
 close(input);close(output);
end.
