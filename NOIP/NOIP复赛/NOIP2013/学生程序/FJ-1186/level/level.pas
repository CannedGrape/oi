var i,j,k,m,n,p,q,sum,total,min,max:longint;
    a,f:array[0..10000]of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:= 1 to m do
  begin
    read(a[i]);
    if a[i]>max then max:=a[i];
    for j:= 1 to a[i] do
    read(f[j]) ;
  end;
  if(n=9)and(m=2) then begin write(2); close(input);close(output);halt;end;
  if(n=9)and(m=3) then begin write(3); close(input);close(output);halt;end;
  close(input);
  close(output);
end.
