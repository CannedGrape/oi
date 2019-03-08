var n,m,k,x:longint;
    d,ans:int64;
procedure work(k:longint);
  var t:int64;
  begin
    t:=10;
    d:=1;
    while k>0 do
      begin
        if odd(k) then d:=(d*t) mod n;
        k:=k shr 1;
        t:=(t*t) mod n;
      end;
  end;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  work(k);
  ans:=(x+(d*m) mod n)mod n;
  writeln(ans);
  close(input);close(output);
end.
