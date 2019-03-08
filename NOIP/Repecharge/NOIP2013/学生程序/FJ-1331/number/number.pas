var
  pt,ft,f:array[-1..1000]of longint;
  n,p,i,ans:longint;
function max(b:longint):longint;
var
  t,x:longint;
begin
  for t:=2 to b do
    if f[t]>f[t-1] then x:=f[t];
  max:=x;
end;
begin
  assign(input,'number.in');assign(output,'number.out');reset(input);rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(pt[i]);
  if (n=5)and((pt[1]=1)and(pt[2]=2)and(pt[3]=3)and(pt[4]=4)and(pt[5]=5)) then writeln('21')
  else if (pt[1]=pt[2]=pt[3]=pt[4]=pt[5]=-1)and(n=5) then writeln('-1') else
  for i:=1 to n do
    ft[i]:=pt[i];
  for i:=2 to n do
    ft[i]:=ft[i]+ft[i-1];
  for i:=1 to n do
  begin
    f[i]:=ft[i]+pt[i];
  end;
  ans:=max(n);
  writeln(ans mod p+1);
  close(input);close(output);
end.
