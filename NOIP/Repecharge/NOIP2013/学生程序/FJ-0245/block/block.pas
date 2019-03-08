var
  a,h:array[0..100000]of longint;
  n,ans,i,j:longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);

  readln(n);
  for i:=1 to n do read(h[i]);
  ans:=0;a[0]:=0;
  a[1]:=h[1];j:=1;
  for i:=2 to n do
  begin
    if h[i]>a[j] then
    begin
      inc(j);
      a[j]:=h[i];
    end
    else begin
      inc(ans,a[j]-h[i]);
      while a[j]>h[i] do dec(j);
      if a[j]<>h[i] then
      begin
        inc(j);
        a[j]:=h[i];
      end;
    end;
  end;
  if j>0 then inc(ans,a[j]);
  writeln(ans);

  close(input);close(output);
end.