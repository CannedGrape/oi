program expr;
var s:array[1..10000] of char;
    a,i,j,k,l,o,p,q,r,t:longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  i:=ord(s[1])-ord('0');
  j:=ord(s[3])-ord('0');
  k:=ord(s[5])-ord('0');
  l:=ord(s[7])-ord('0');
  a:=i+j*k+l;
  p:=a div 1000;
  q:=a div 100;
  r:=a mod 10;
  t:=a div 10;
  if a>9999 then
    writeln(p*1000+q*100+r+t*10)
  else
  writeln(a);
  close(input);
  close(output);
end.

