{ NOI 2002 Day 2 Problem 1 Savage.pas, by Rujia Liu }
const
  maxn=15;
  maxm=1000000;
var
  pab,cab:array[1..maxn,1..maxn] of longint;
  c,p,l:array[1..maxn] of longint;
  max,i,j,n,m:longint;

{extended gcd finding (x,y) satisfying that ax+by=d}
procedure Gcd(a,b:longint; var d,x,y:longint);
var c,t:longint;
begin
  c:=a mod b;
  if c=0 then begin d:=b; x:=0; y:=1; end
  else begin
    Gcd(b,c,d,x,y);
    t:=x;
    x:=y;
    y:=t-a div b*y;
  end;
end;

{is the m correct?}
function check:boolean;
var i,j,mm,a,b,d,x,y,ans:longint;
begin
  check:=false;
  for i:=1 to n do
    for j:=i+1 to n do
    begin
      a:=pab[i,j];
      b:=cab[i,j];
      {ax=b(mod m)}
      gcd(a,m,d,x,y);
      if b mod d<>0 then continue; {they will never meet, good!}
      a:=a div d;
      b:=b div d;
      mm:=m div d;
      {a'x=b'(mod mm), gcd(a',mm)=1}
      gcd(a,mm,d,x,y);
      ans:=x*b;
      while ans<0 do ans:=ans+mm;
      while ans>=mm do ans:=ans-mm;
      {ans is the smallest answer for ax=b(mod mm)}
      if (ans<=l[i])and(ans<=l[j]) then exit;
    end;
  check:=true;
end;

begin
  {init}
  assign(input,'savage.in');
  reset(input);
  assign(output,'savage.out');
  rewrite(output);
  {read input}
  read(n);
  max:=0;
  for i:=1 to n do
  begin
    read(c[i],p[i],l[i]);
    dec(c[i]);
    if c[i]>max then max:=c[i];
  end;
  for i:=1 to n do
    for j:=i+1 to n do
    begin
      {build equation pab*x=cab(mod m)}
      pab[i,j]:=p[i]-p[j];
      cab[i,j]:=c[j]-c[i];
      if pab[i,j]<0 then
      begin
        pab[i,j]:=-pab[i,j];
        cab[i,j]:=-cab[i,j];
      end;
    end;
  for m:=max+1 to maxm do
    if check then
    begin
      writeln(m);
      break;
    end;
  close(input);
  close(output);
end.
