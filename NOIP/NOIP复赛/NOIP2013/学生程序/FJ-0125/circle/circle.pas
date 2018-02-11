var i,j,n,t,k,y,d,e,m,x,c:longint;
a,b:array[0..10000] of longint;
begin
 assign(input,'circle.in');
 reset(input);
 assign(output,'circle.out');
 rewrite(output);
c:=1;
e:=10;
readln(n,m,k,x);
y:=n;
 for i:=1 to k-1 do
  e:=e*10;
 t:=(((e*m)mod n) +1);
 for i:=t+1 to n-1 do
 begin
 a[i]:=c;
 inc(c);
 end;
 for i:=t-1 downto 0 do
 begin
  a[i]:=n;
  dec(n);
 end;
 a[t]:=0;
 for i:=1 to n do
 if a[i]=x then
 begin
 writeln(i-1);
 break;
 end;
 readln;
 readln;
 close(input);
close(output);
end.
