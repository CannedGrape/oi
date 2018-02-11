var
  ans:array[0..9] of longint;
  s:string;
  i,j:longint;
  n,x:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  fillchar(ans,sizeof(ans),0);
  for i:=1 to n do
    begin
    str(i,s);
    for j:=1 to length(s) do inc(ans[ord(s[j])-48]);
    end;
  writeln(ans[x]);
  close(input);
  close(output);
end.