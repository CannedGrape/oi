var ans,n,m,k,x:int64;
procedure ksm(x:int64);
begin
  if x=1 then ans:=10 mod n else
  begin
    if odd(x) then
    begin
      ksm(x-1);
      ans:=ans*10 mod n;
    end
    else
    begin
      ksm(x div 2);
      ans:=ans*ans mod n;
    end;
  end;
end;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  ksm(k);
  ans:=((ans*m) mod n+x) mod n;
  writeln(ans);
  close(input);
  close(output);
end.

