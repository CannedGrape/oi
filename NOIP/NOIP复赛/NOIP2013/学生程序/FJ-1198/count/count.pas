var
  ch:char;
  n,num,i,ans,j:longint;
  s:string;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,num);
  ch:=chr(num+ord('0'));
  ans:=0;
  for i:=1 to n do
  begin
    str(i,s);
    for j:=1 to length(s) do
    if s[j]=ch then inc(ans);
  end;
  writeln(ans);
  close(input);
  close(output);
end.
