var n,max,i,sum,j,ans:longint;
    h:array[1..100001]of longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  max:=0;
  for i:=1 to n do
    begin
      read(h[i]);
      if h[i]>max then max:=h[i];
    end;
  ans:=0;
  for i:=1 to max do
    begin
      sum:=0;
      j:=1;
      repeat
        while (j<n)and(h[j]<i)  do inc(j);
        if (j=n)and(h[n]<i) then break;
        while (j<n)and(h[j]>=i) do inc(j);
        if j<=n then inc(sum);
      until j=n;
      inc(ans,sum);
    end;
  writeln(ans);
  close(input);close(output);
end.