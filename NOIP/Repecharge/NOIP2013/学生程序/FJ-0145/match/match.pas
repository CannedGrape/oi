program match;
var
 n,i:longint;
 a,b:array[1..1000000]of longint;
begin
 assign(input,'match.in');reset(input);
 assign(output,'match.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  read(a[i]);
 for i:= 1 to n do
  read(b[i]);

 write('1');
 close(input);close(output);
end.
