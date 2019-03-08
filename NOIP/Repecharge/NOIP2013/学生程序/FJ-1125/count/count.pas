var
  n,x,i,j,k,sum:longint;
  s,s1:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);str(x,s1);sum:=0;
  for i:=1 to n do
    begin
      str(i,s);
      k:=pos(s1,s);
      if k=0 then continue;
      while k<>0 do
        begin
          inc(sum);
          delete(s,k,1);
          k:=pos(s1,s);
        end;
    end;
  writeln(sum);
  close(input);
  close(output);
end.
