program circle;
var
 n,m,k,x,sum:int64;

function mi(x:int64):int64;
var i,j:int64;
begin
 if x=0 then exit(1);
 if x=1 then mi:=10 mod n
 else begin
  i:=x mod 2;
  j:=mi(x div 2)mod n;
  mi:=(j*j) mod n;
  if i=1 then mi:=(mi*10)mod n;
 end;
end;

begin
 assign(input,'circle.in'); reset(input);
 assign(output,'circle.out'); rewrite(output);
 readln(n,m,k,x);
 sum:=x+mi(k)*m;
 while(sum>=n)do sum:=sum-n;
 writeln(sum);
 close(input); close(output);
end.
