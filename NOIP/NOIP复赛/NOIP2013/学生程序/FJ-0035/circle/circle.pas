var n,k,m,ans,x:int64;
function power(l:int64):int64;
var tmp:int64;
begin
  power:=1;  tmp:=10;
  while l<>0 do
    begin
      if l and 1=1 then power:=(power*tmp) mod n;
      l:=l shr 1;
      tmp:=(tmp*tmp) mod n;
    end;
end;
begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  ans:=(power(k)*m) mod n;
  ans:=(ans+x) mod n;
  writeln(ans);
close(input);close(output);
end.