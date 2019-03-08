var n,tx,i,j,ans:longint;
    tstr:string;
    x:char;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,tx);
  x:=chr(tx+48);
  ans:=0;
  for i:=1 to n do
  begin
    str(i,tstr);
    for j:=1 to length(tstr) do
      if tstr[j]=x then inc(ans);
  end;
  writeln(ans);
  close(output);
  close(input);
end.
