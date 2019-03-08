  var
    n,x,i,sum,p:longint;
    s,ss:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  str(x,ss);
  sum:=0;
  for i:=1 to n do
    begin
      str(i,s);
      p:=pos(ss,s);
      while p>0 do
        begin
          inc(sum);
          delete(s,p,1);
          p:=pos(ss,s);
        end;
    end;
  writeln(sum);
  close(input);
  close(output);
end.