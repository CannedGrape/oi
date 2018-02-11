program count;
var n,x,num:int64;
    i,j:longint;
    s,z:string;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
 readln(n,x);
 str(x,z);
 for i:=1 to n do
begin
  str(i,s);
  for j:=1 to length(s) do
begin
  if s[j]=z then inc(num);
end; end;
 writeln(num);
close(input);close(output);
end.