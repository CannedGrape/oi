var a:array[0..100005]of longint;
    n,i,sum,ans,j,k:longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
  read(a[i]);
  sum:=sum+a[i];
  end;
  ans:=0;
  while sum>0 do
  begin
    j:=0;
    while j<n do
      begin
       i:=j+1;
       while (a[i]=0) and (i<=n) do inc(i);
       if i>n then break;
       j:=i+1;
       while (a[j]<>0) and (j<=n) do inc(j);
       if (j=i+1) and ((a[i-1]=0) and (a[i+1]=0)) then
         begin
           sum:=sum-a[i];
           ans:=ans+a[i];
           break;
         end
       else
         begin
       sum:=sum-(j-i);
       for k:=i to j-1 do a[k]:=a[k]-1;
       ans:=ans+1;
       end;
      end;
  end;
  writeln(ans);
  close(input);close(output);
end.
