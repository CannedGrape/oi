program count;
var i,j,n,x,ans:longint;
    s:string;ch:char;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
  readln(n,x);
  ch:=chr(x+48);
  for i:=1 to n do
  begin
    str(i,s);
    for j:=1 to length(s)do
    if s[j]=ch then ans:=ans+1;
  end;
  write(ans);
end.
