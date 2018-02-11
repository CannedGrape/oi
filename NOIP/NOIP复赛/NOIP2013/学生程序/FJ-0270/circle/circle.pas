var n,m,k,x:int64;
function pow(a,b,p:int64):int64;
begin
  pow:=1;
  a:=a mod p;
  while b>0 do
  begin
    if b and 1=1 then pow:=(pow*a) mod p;
    a:=(a*a) mod p;
    b:=b shr 1;
  end;
end;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  writeln((x+m*pow(10,k,n)) mod n);
  close(input);close(output);
end.
