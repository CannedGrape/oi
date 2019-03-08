var
  ans,n,x,i:longint;
  a:array[-10..1000000]of longint;
begin
  assign(input,'count.in');assign(output,'count.out');reset(input);rewrite(output);
  readln(n,x);
  for i:=1 to n do
    a[i]:=i;
  if x=0 then ans:=n div 10 else
  if n<10 then if n<x then ans:=0
  else ans:=1
  else if n<100 then
  if (n div 10<=x) then
  if x>n mod 10 then ans:=1+(n div 10)-1
  else if x=n mod 10 then ans:=1+2+(n div 10)
  else ans:=1+(n div 10)
  else if x>n mod 10 then ans:=11+(n div 10)-1
  else ans:=11+(n div 10);
  writeln(ans);
   close(input);close(output);
end.
