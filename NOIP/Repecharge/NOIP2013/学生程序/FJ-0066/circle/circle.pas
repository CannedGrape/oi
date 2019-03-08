var i,j,k,n,m,x,ch,kk:longint;
    a,b:array[0..50]of int64;
begin

assign(input,'circle.in');assign(output,'circle.out');reset(input);rewrite(output);
  read(n,m,k,x);
  b[0]:=1;
  a[0]:=10;
  for i:=1 to 40 do
      begin
        b[i]:=b[i-1]*2;
        a[i]:=a[i-1]*a[i-1] mod n;
      end;
  j:=40; kk:=k; ch:=m;
  repeat
    if  kk>=b[j] then
     begin
       for i:=1 to kk div b[j] do
       ch:=ch*a[j] mod n;
       kk:=kk mod b[j];
     end;
    if kk<b[j] then dec(j);
  until kk=0;
  write((x+ch)mod n);
close(input);close(output);
end.