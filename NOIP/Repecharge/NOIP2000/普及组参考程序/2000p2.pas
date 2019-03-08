const
  maxn=50;
  maxm=10000;
var
  d:array[1..maxm] of longint;
  price:array[1..maxn] of longint;
  sell:array[1..maxn] of longint;

  k1,k2:real;

  i,j:longint;
  r,t,x,y,n,each:longint;
  p,most,m:longint;
  u1,u2:longint;

  c:longint;
begin
  readln(n);
  c:=0;
  repeat
    readln(x,y);
    if (x=-1)and(y=-1) then break;
    inc(c);
    price[c]:=x;
    sell[c]:=y;
  until false;
  readln(m);

  p:=price[1];
  most:=price[c]+sell[c] div m;

  if (n<p)or(n>most) then {we can't sell at this price!!}
  begin
    writeln('NO SOLUTION');
    halt;
  end;

  for i:=1 to c-1 do
  begin
    each:=(sell[i]-sell[i+1]) div (price[i+1]-price[i]);
    for j:=price[i] to price[i+1]-1 do
      d[j]:=sell[i]-each*(j-price[i]);
  end;
  for i:=price[c] to most do
    d[i]:=sell[c]-m*(i-price[c]);

  {calcutate k1 and k2 such that k1<=x<=k2}
  k1:=-1e20; k2:=1e20;
  for i:=p to most do
  begin
    r:=d[n]-d[i];
    t:=i*d[i]-n*d[n]-p*(d[i]-d[n]);
    if (r>0) and (t/r>k1) then {x>=t/r}
      k1:=t/r;
    if (r<0) and (t/r<k2) then {x<=t/r}
      k2:=t/r;
  end;

  if k1<-1e19 then u1:=-maxlongint {too small}
  else if (k1>0)and(k1-int(k1)>1e-8) then u1:=trunc(k1)+1 else u1:=trunc(k1);

  if k2>1e19 then u2:=maxlongint {too big}
  else if (k2<0)and(int(k2)-k2>1e-8) then u2:=trunc(k2)-1 else u2:=trunc(k2);

  if ((u1<0)and(u2>0))or((u2>0)and(u1<0)) then {contains 0}
  begin
    u1:=0; u2:=0;
  end;

  if u1>u2 then writeln('NO SOLUTION')
  else if abs(u1) < abs(u2) then writeln(u1)
  else writeln(u2);
end.
