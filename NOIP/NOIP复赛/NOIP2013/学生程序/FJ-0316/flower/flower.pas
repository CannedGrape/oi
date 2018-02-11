var max:array[0..100000] of longint;
    h:array[0.. 100000] of longint;
    s1,n,i,j,t:longint;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
  readln(n);
  fillchar(max,sizeof(max),0);
  fillchar(h,sizeof(h),0);
  for i:=1 to n do read(h[i]);

  {da xiao da}
  for i:=1 to n do
    if h[i]>h[i-1] then max[i]:=max[i-1]+1;
  s1:=n;t:=0;
  for i:=1 to n do if (max[i]=0) and (max[i-1]=0) then inc(max[i]);
  for i:=1 to n do
    if max[i]=0 then
      begin
        s1:=s1-(i-t-1)+1;
        t:=i;
      end;
  if max[n]=0 then s1:=s1-(n-t)
  else s1:=s1-(n-t)+1;

  {xiao da xiao
  for i:=n downto 1 do
    if h[i]>h[i+1] then min[i]:=min[i+1]+1;
  s2:=n;t:=0;
  for i:=1 to n do if min[i]=0 and min[i+1]=0 then inc(min[i]);
  for i:=n downto 1 do
    if min[i]=0 then
      begin
        s2:=s2-()
      end; }

 writeln(s1);
close(input);close(output);

end.
