var g:array[0..100001]of longint;
    i,j,k,n:longint;
    ans:int64;
begin
  assign(input,'block.in');  reset(input);
  assign(output,'block.out');  rewrite(output);
  readln(n);
  ans:=0;
  for i:=1 to n do
    begin
      read(g[i]);
      if g[i]>g[i-1] then inc(ans,g[i]-g[i-1]);
    end;
  writeln(ans);
  close(input); close(output);
end.
