var h:array[0..100500]of longint;
    n,i:longint;
    ans:int64;
begin

assign(input,'block.in');
assign(output,'block.out');
reset(input);rewrite(output);
  read(n);
  for i:=1 to n do read(h[i]);
  ans:=h[1];
  for i:=2 to n do
   if h[i]>h[i-1] then ans:=ans+h[i]-h[i-1];
  write(ans);

close(input);
close(output);

end.