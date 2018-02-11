program circle;
var
i,c,n,m,k,x:longint;
a:array[1..400000000] of longint;
begin
 assign(input,'circle.in');
 reset(input);
 assign(output,'circle.out');
 rewrite(output);
 readln(n,m,k,x);
 for i:=1 to k do
 a[i]:=0;
 a[k+1]:=1;
 for i:=k downto 1 do
  a[i]:=a[i+1]*10 mod n ;
 for i:=1 to a[1] do
  begin
  x:=x+m;
  if x>=n then x:=x-n;
  end;
  writeln(x);
 close(input);
 close(output);
 end.
