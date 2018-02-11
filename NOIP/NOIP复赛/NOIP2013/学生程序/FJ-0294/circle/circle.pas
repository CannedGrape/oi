var i,j,k,m,n,x,y,z,a,b,l:longint; t,p:qword;
    mo:array[0..1000000] of longint;
function gcd(a,b:longint):longint;
   begin
    if b=0 then gcd:=a else gcd:=gcd(b,a mod b);
   end;
begin
 assign(input,'circle.in'); reset(input);
 assign(output,'circle.out'); rewrite(output);
 readln(n,m,k,x);
 t:=n*m div gcd(n,m) div m;
 p:=10; j:=1;
 while p<=t do begin p:=p*10; inc(j); end;
 y:=p mod t; p:=p*10; i:=1; mo[1]:=p mod t;
 while (p mod t<>y) and (i<=k) do
  begin
   mo[i]:=p mod t;
   p:=p mod t;
   p:=p*10;
   inc(i);
  end;
 if i<=k then begin z:=(k-j) mod i;  l:=mo[z] end else l:=k;
 for  j:=1 to l do x:=(x+m) mod n;
 writeln(x);
 close(input); close(output);
end.
