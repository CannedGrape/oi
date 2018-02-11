program circle;
var
 n,m,c,a,b,k,r,x,t:int64;

procedure gongyue(n,m:int64);
begin
  a:=n;  b:=m;
  r:=a mod b;
  while r<>0 do
  begin
    a:=b;  b:=r;
    r:=a mod b;
  end;
  t:=m*n div b;
  c:= trunc(exp(k*ln(10))) mod t;
  if c=0 then writeln(x)
		else
			begin
		      x:=(c*m+x) mod n;
		      writeln(x);
		    end;
end;

begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);
read(n,m,k,x);
gongyue(n,m);
close(input);
close(output);
end.

