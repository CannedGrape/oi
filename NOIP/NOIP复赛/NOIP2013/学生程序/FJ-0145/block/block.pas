program block;
var
 n,i:longint;
 a:array[1..10000]of longint;
begin
 assign(input,'block.in');reset(input);
 assign(output,'block.out');rewrite(output);
  readln(n);
  for i:= 1 to n do
   read(a[i]);
  writeln(n);
 close(input);close(output);
end.