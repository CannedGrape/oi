program number;
  var n,u,i,max:longint;
      sum,ans,a:array[0..10000]of longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  reset(output);
  read(n,u);sum[0]:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      sum[i]:=(sum[i-1]+a[i])mod u;
    end;
  ans[1]:=sum[1];
  for i:=2 to n do
    if sum[i-1]>sum[i-2] then ans[i]:=(ans[i-1]+ans[i-1]-sum[i-2]+sum[i-1])mod u
      else ans[i]:=ans[i-1] mod u;
  max:=0;
  for i:=1 to n do
    if ans[i]>max then max:=ans[i];
  if max<0 then write('-',(abs(max)div 2)mod u)else
  write((max div 2) mod u);
  close(input);
  close(output);
end.