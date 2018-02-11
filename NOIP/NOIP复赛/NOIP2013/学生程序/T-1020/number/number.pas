var i,k,j,p,n,m,max:longint;
    a,b,c:array[1..1000000] of longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  read(n,m);readln;
  max:=-1000000000;
  for i:=1 to n do read(a[i]);
  b[1]:=a[1];
  c[1]:=b[1];
  for i:=2 to n do
  begin
    k:=i;
    p:=i;
    while k>0 do
    begin
      if a[k]>0 then
      b[p]:=b[p]+a[k];
      dec(k);
    end;
  end;
  for i:=2 to n do
      c[i]:=c[i-1]+b[i-1];
  for i:=1 to n do
      if max<c[i] then max:=c[i];
  if max<0 then begin write('-');max:=max+2*max; end;
  max:=max mod m;
  write(max);
  close(input);
  close(output);
end.
