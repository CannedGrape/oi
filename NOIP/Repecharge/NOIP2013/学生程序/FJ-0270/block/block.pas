var n,i,ans,top:longint;
    h:array[0..100010]of longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  ans:=0;
  while true do
  begin
    top:=0;
    for i:=1 to n do
      if h[i]>top then top:=h[i];
    if top=0 then break;
    i:=1;
    while i<=n do
    begin
      if h[i]=top then
      begin
        while (i<=n)and(h[i]=top) do
        begin
          dec(h[i]);inc(i);
        end;
        inc(ans);
      end;
      inc(i);
    end;
  end;
  writeln(ans);
  close(input);close(output);
end.