var
  a:array[0..1000000]of longint;
  n,m,t,max,min,w,i,j,l,r,s,k:longint;
  ans:int64; q:boolean;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  ans:=0;i:=0;q:=true;max:=0;min:=0;
  repeat
    inc(i);
    if q and(a[i]>a[i-1]) then max:=a[i];
    if q and(a[i]<a[i-1]) then q:=false;
    if ((not q)and(a[i]>a[i-1]))or(i=n+1) then
      begin
        ans:=ans+max-min;
        q:=true;
        min:=a[i-1];max:=a[i];
      end;
  until i>n;
  writeln(ans);
  close(input);close(output);
end.


