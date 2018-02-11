program flower;
var
m,i,n:longint;
h:array[1..100000] of longint;
begin
 assign(input,'flower.in');
 reset(input);
 assign(output,'flower.out');
 rewrite(output);
 readln(n);
 for i:=1 to n do
  read(h[i]);
 m:=(n div 2)+1;
 writeln(m);
 close(input);
 close(output);
end.
