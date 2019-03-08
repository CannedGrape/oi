var
  n,m,k,x,i,ans:longint;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  ans:=m;i:=10;
  while k>0 do
  begin
    if k mod 2=1 then
    begin
      ans:=(ans*i)mod n;
      dec(k);
    end;
    i:=(i*i)mod n;
    k:=k div 2;
  end;
  ans:=(ans+x) mod n;
  writeln(ans);
  close(input);close(output);
end.             