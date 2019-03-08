var n,m,k,x:longint;
    t:qword;
function power(a,b:longint):qword;
var t,ans:qword;
begin
  ans:=1;
  t:=a;
  while b<>0 do
    begin
      if b and 1=1 then ans:=(ans*t) mod n;
      t:=(t*t) mod n;
      b:=b div 2;
    end;
  exit(ans);
end;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);

  readln(n,m,k,x);
  t:=power(10,k) mod n;
  t:=(t*m) mod n;
  t:=(t+x) mod n;
  writeln(t);

close(input);
close(output);
end.