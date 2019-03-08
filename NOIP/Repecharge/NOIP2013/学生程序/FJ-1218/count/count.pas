var ans,i,j,n,k:longint;
    s:string;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,k);
  ans:=0;
  for i:=1 to n do
  begin
    str(i,s);
    for j:=1 to length(s) do
    if ord(s[j])-48=k then inc(ans);
  end;
  write(ans);
  close(input);close(output);
end.
