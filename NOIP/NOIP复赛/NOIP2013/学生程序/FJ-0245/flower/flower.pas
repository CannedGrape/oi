var
  a,b:array[1..50000]of longint;
  h:array[1..100000]of longint;
  n,i,j,k,ans:longint;
  f:boolean;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);

  readln(n);
  for k:=1 to n do read(h[k]);
  k:=1;
  while(k<=n)and(h[1]=h[k])do inc(k);
  if k<=n then
  begin
    i:=1;j:=1;
    if h[1]<h[k] then
    begin
      a[i]:=h[1];b[j]:=h[k];
      for k:=k+1 to n do
        if i<=j then
        begin
          if h[k]<b[j] then
          begin
            inc(i);
            a[i]:=h[k];
          end else b[j]:=h[k];
        end else
        begin
          if h[k]>a[i] then
          begin
            inc(j);
            b[j]:=h[k];
          end else a[i]:=h[k];
        end;
    end
    else begin
      a[i]:=h[k];b[j]:=h[1];
      for k:=k+1 to n do
        if i<j then
        begin
          if h[k]<b[j] then
          begin
            inc(i);
            a[i]:=h[k];
          end else b[j]:=h[k];
        end else
        begin
          if h[k]>a[i] then
          begin
            inc(j);
            b[j]:=h[k];
          end else a[i]:=h[k];
        end;
    end;
    ans:=i+j;
  end else ans:=1;
  writeln(ans);
  close(input);close(output);
end.