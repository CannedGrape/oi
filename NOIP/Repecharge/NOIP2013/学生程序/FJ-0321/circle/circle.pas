program fuck;
uses math;
var
 i,j,k,m,n,x,t:longint;
 s,l:int64;
 a:array[1..100] of longint;
begin
 assign(input,'circle.in');
 assign(output,'circle.out');
 reset(input);
 rewrite(output);
 readln(n,m,k,x);
 s:=10**(k mod 10) mod n;
 l:=10 mod n;
 k:= k div 10;
 while k>0 do
  begin
  l:=l**10 mod n;
  s:=(s* (l**(k mod 10) mod n)) mod n;
  k:=k div 10;
  end;
 writeln( ((x mod n)+(m mod n)*(s mod n) mod n) mod n);
 close(input);
 close(output);
end.

