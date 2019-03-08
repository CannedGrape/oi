var i,j,n,k,max:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  read(i,j);
  for n:=1 to i do
  begin
      k:=n;
      while k<>0 do
      begin
        if k mod 10=j then inc(max);
        k:=k div 10;
      end;
  end;
  write(max);
  close(input);
  close(output);
end.
