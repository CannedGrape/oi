var
  a,b:array[0..1000000]of longint;
  n,m,k,i,j,l,t:longint;
  s,x:int64;

function q1(l:longint):int64;
begin
  if l =1 then q1:=10
  else begin
         q1:=sqr(q1(l div 2)) mod n;
         if l mod 2=1 then q1:=q1*10 mod n;
       end;
end;


begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  s:=q1(k) mod n;
  x:=(x+(s*m mod n)) mod n;
  writeln(x);
  readln;readln;
  close(input);close(output);
end.