program count;
var
  n,i,j,x,k,sum:longint;
  s,a:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  str(x,a);
  sum:=0;
  for i:=1 to n do
  begin
    str(i,s);
    k:=length(s);
    for j:=1 to k do
    if s[j]=a then inc(sum);
  end;
  writeln(sum);
  close(input);
  close(output);
end.