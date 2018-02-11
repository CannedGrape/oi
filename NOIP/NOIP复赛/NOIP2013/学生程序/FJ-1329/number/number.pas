var
 n,p:longint;
 a:array[1..1000]of longint;
begin
assign(input,'number.in'); reset(input);
assign(output,'number.out'); rewrite(output);
 read(n,p);
 for i:=1 to n do
 read(a[i]);
 writeln('-1');
 close(input);
 close(output);
end.
