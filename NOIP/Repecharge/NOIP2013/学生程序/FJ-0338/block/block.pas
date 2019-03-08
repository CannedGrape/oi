var h:array[0..100000]of longint;
    i,n,num:longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(h[i]);readln;
    num:=h[1];
    for i:=2 to n do
      if h[i]>h[i-1] then num:=num+h[i]-h[i-1];
    writeln(num);
  close(input);close(output);
end.
