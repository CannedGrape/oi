program flower;
var
 a,b:array[1..100000]of integer;
 c,d,i,j,p,n,m:integer;
begin
 assign(input,'flower.in');
 assign(output,'flower.out');
 reset(input);
 rewrite(output);
 readln(n);
 for i:=1 to n do read(a[i]);
 readln;
 c:=n div 2+1;
 writeln(c);
 close(input);
 close(output);
end.
