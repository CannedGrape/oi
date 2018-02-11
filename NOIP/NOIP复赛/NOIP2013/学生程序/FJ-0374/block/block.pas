var a:array[1..100000] of longint;
    r,min,n,i,ans:longint;
 begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
   read(a[i]);
  min:=a[1];
  for i:=1 to n do
   if a[i]<min then min:=a[i];
  ans:=min;
  i:=1;
  repeat
   if (a[i]=a[i+1]) and (i+1<=n) then
    begin
     r:=a[i];
     while (a[i]=a[i+1]) and (i+1<=n) do inc(i);
    end;
   if (a[i]>a[i+1]) and (i+1<=n) then
    begin
     r:=a[i];
     while (a[i]>=a[i+1]) and (i+1<=n) do inc(i);
     ans:=ans+r-min;
     inc(i);
    end;
   if (a[i]<a[i+1]) and (i+1<=n) then
    begin
     while (a[i]<=a[i+1]) and (i+1<=n) do inc(i);
     r:=a[i];
     ans:=ans+r-min;
     inc(i);
    end;
   if i=n then begin ans:=ans+a[i]-min; inc(i); end;
  until i>n;
  writeln(ans);
  close(input);
  close(output);
 end.