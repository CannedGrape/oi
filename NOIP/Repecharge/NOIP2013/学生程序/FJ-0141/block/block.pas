var k,now,i,n:longint;ans:int64;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(k);
    if k>now then ans:=ans+k-now;
    now:=k;
  end;
  writeln(ans);
  close(input);
  close(output);
end.