
var a:array[1..100001] of integer;
    i,j,n:longint;
    min,time,ans:integer;

//____________________________________
procedure iin;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
end;
procedure oout;
begin
  close(input);
  close(output);
end;
//_____________________________________
begin
  iin;
  readln(n);
  for i:=1 to n do read(a[i]);
  i:=1;
  time:=0;
  ans:=0;
  while i<=n do
   begin
    inc(ans);
    if a[i+1]>=a[i] then
     begin
      for j:=i to n-1 do
       if a[j]>a[j+1] then break;
      if (j=n-1)and(a[j+1]>=a[j]) then inc(j);
      time:=time+a[j];
      i:=j+1;
     end
    else
     begin
      for j:=i to n-1 do
       if a[j]<=a[j+1] then break;
      if (j=n-1)and(a[j+1]<a[j]) then inc(j);
      time:=time+a[i];
      i:=j+1;
     end;
   end;
  min:=10001;
  for i:=1 to n do
   if a[i]<min then min:=a[i];
  if ans<>1 then time:=time-min;
  write(time);
  oout;
end.
