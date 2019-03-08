var n,x,i,a,ans:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  read(n,x);ans:=0;
  for i:=1 to n do
    begin
      a:=i;
      while a>9 do
        begin
          if (a mod 10)=x then inc(ans);
          a:=a div 10;
        end;
      if a=x then inc(ans);
    end;
  write(ans);
  close(input);close(output);
end.
