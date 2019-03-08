var i,n,ans,max,j,t,min:longint;h:array[0..100001] of integer;f:array[0..10000] of boolean;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  read(h[i]);
  ans:=0;
  max:=h[1];
  min:=h[1];
  fillchar(f,sizeof(f),true);
  while max>0 do
  begin
  max:=0;
  t:=1;
  for i:=1 to n+1 do
  begin
    if (h[i]<min)and(h[i]>0) then min:=h[i];
    if (h[i]=0)and(h[i-1]>0) then
    begin
      for j:=t to i-1 do
      if h[j]>0 then
      h[j]:=h[j]-min;
      ans:=ans+min;
      if i=n+1 then t:=1;
      if i<>n+1 then t:=i+1;
    end;
    if h[i]>max then max:=h[i];
  end;
  end;
  {for i:=1 to n+1 do
  min:=f[1];
  while min>0 do
  begin
  for i:=1 to  n do
  if (f[i]<min)and(f[i]>0) then  min:=h[i];}
  writeln(ans);
  close(input);close(output);
end.




