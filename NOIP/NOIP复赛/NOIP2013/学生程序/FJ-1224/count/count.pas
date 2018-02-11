var n,x,i,t,s,ans:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,x);
  ans:=0;
  for i:=1 to n do
    begin
      t:=i;
      repeat
        s:=t mod 10;
        if s=x then inc(ans);
        t:=t div 10;
      until t=0;
    end;
  writeln(ans);
  close(input);close(output);
end.