var
  n,m,k,x,j,sum,q,a:int64;
  i:longint;
begin
  assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input);
  rewrite(output);
  readln(n,m,k,x);
  q:=1;
  sum:=1;
  a:=10;
  while k>0 do
  begin
    if k mod 2=1 then q:=(q*a) mod n;
    k:=k div 2;
    a:=(a*a) mod n;
  end;
  writeln((q*m+x) mod n);
  close(input);
  close(output);
end.
