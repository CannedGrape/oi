program count;
var  n,x,i,k,sum:longint;
begin
  assign(input,'count.in'); assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(n,x);
  sum:=0;
  for i:=1 to n do
    begin
       k:=i;
      if k mod 10=x then inc(sum);
      while k<>0 do
        begin
          k:=k div 10;
          if k mod 10=x then inc(sum);
        end;
    end;
  write(sum);
  close(input);close(output);
end.
