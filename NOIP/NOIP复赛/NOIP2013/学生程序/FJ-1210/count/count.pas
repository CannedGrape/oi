var i,n,x,y,num:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
    readln(n,x);num:=0;
    for i:=1 to n do
    begin
      y:=i;
      while y>0 do
      begin
        if y mod 10=x then inc(num);y:=y div 10;
      end;
    end;
    writeln(num);
  close(input);close(output);
end.
