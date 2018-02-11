program count;
var n,x,a,b,c,s:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  read(n,x);
  for a:=1 to n do
    begin
      b:=a;
      repeat
        if b mod 10=x then s:=s+1;
        b:=b div 10;
      until b=0;
    end;
  write(s);
  close(input);close(output);
end.
