var
  num,tezh,point:array[0..1000000] of longint;
  now,max,sum,i,j,k,ans,n,p:longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do point[i]:=-maxlongint;
  for i:=1 to n do read(num[i]);
  tezh[1]:=num[1];
  point[1]:=num[1];
  for k:=1 to n do
  begin
    max:=-maxlongint;
    for i:=1 to k do
    begin
      now:=0;
      for j:=i to k do
      now:=now+num[j];
      if now>max then max:=now;
    end;
    if tezh[k-1]>tezh[k] then tezh[k]:=tezh[k-1] else tezh[k]:=max;
  end;
 // for i:=1 to n do write(tezh[i],' ');
  sum:=point[1];
  for i:=2 to n do
    for j:=1 to i-1 do
    begin
      if tezh[j]+point[j]>point[i] then point[i]:=tezh[j]+point[j];
      if point[i]>sum then sum:=point[i];
     // writeln(sum);
    end;
  if sum<0 then write('-');
  sum:=abs(sum) mod p;
  write(sum);
  close(input);close(output);
end.
