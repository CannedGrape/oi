var
 n,jilu,cucuen,i,j,od,h:longint;
 a,b,c:array[1..100000]of longint;
begin
 assign(input,'number.in');reset(input);
 assign(output,'number.out');rewrite(output);
 read(n); readln(od);
 for i:=1 to n do
 begin
 read(a[i]);
 if a[i]<0 then begin write('-');write(abs(a[i])mod od);
 close(input);close(output);
 halt; end;
 end;
 for i:=2 to n+1 do
 begin
 jilu:=(jilu+a[i-1])mod od;

 b[i]:=jilu mod od;
 end;
 cucuen:=b[2];
 for i:=3 to n+2 do
 begin
 c[i]:=cucuen mod od;
 cucuen:=(cucuen+b[i-1]) mod od;
 end;
 h:=c[i] mod od;
 writeln(h);
 close(input);close(output);
end.
