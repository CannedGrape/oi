program Project1;
var n,x,i,j,sum:longint;
    p,s:string;
begin
  assign(input,'count.in');   assign(output,'count.out');
  reset(input);    rewrite(output);
  readln(n,x);
  str(x,p);
  sum:=0;
  for i:=1 to n do
    begin
    str(i,s);
    for j:=1 to length(s) do
      if s[j]=p then sum:=sum+1;
    end;
  writeln(sum);
  close(input);
  close(output);
end.