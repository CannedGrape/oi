program ex;
const maxn=1000000;
var zx,i,j,m,n,k,x,q,qw,ans,q1,q2,q3,q4:longint;
    a,b,c:array[0..1000000] of longint;

function gcd(a,b:longint):longint;
begin
 if b=0 then gcd:=a
  else
   gcd:=gcd(b,a mod b);
end;
procedure print(xx:longint);
begin
 assign(output,'circle.out');
 rewrite(output);
  writeln(xx);
 close(output);
 halt;
end;

procedure cheng1;
var i,j,l:longint;
begin
 for i:=1 to a[0] do
  a[i]:=a[i]*10;
 for i:=1 to a[0] do
  begin
   a[i+1]:=a[i+1]+(a[i] div maxn);
   a[i]:=a[i] mod maxn;
  end;
 while a[a[0]+1]<>0 do inc(a[0]);
end;
function check:boolean;
var l,i,j:longint;
begin
 b[1]:=b[1]+zx;
 i:=1;
 while b[i]>=maxn do
  begin
   b[i+1]:=b[i+1]+(b[i] div maxn);
   b[i]:=b[i] mod maxn;
   inc(i);
  end;
 while b[b[0]+1]<>0 do inc(b[0]);
 if b[0]>a[0] then exit(false);
 if b[0]<a[0] then exit(true);
 l:=a[0];
 while (a[l]=b[l])and(l>0) do dec(l);
 if b[l]>=a[l] then exit(false)
  else exit(true);
end;

procedure work;
var i,j,qq1,qq2:longint;
begin
  i:=k div 6;
  j:=k mod 6;
  qq2:=1;
  for qq1:=1 to j do
   qq2:=qq2*10;
  a[i+1]:=qq2;
  a[0]:=i+1;
  b[1]:=0;
  b[0]:=0;
  while check do
   begin
    for i:=0 to b[0] do
     c[i]:=b[i];
   end;
  zx:=maxn-b[1];
  ans:=x;
  for i:=1 to zx do
   ans:=(ans+m) mod n;
  print(ans);
end;

begin
 assign(input,'circle.in');
 reset(input);
 readln(n,m,k,x);
 close(input);
 zx:=gcd(n,m);
 zx:=n div zx;
 if k<7 then
  begin
   q:=1;
   for i:=1 to k do
    q:=q*10;
   qw:=q mod zx;
  ans:=x;
  for i:=1 to qw do
   ans:=(ans+m) mod n;
  print(ans);
  end
 else
  begin
   if (zx>0)and(zx<=10) then begin q1:=10;i:=1;end
    else
      if (zx>10)and(zx<=100) then begin q1:=100;i:=2;end
    else
      if (zx>100)and(zx<=1000) then begin q1:=1000;i:=3;end
    else
      if (zx>1000)and(zx<=10000) then begin q1:=10000;i:=4;end
    else
      if (zx>10000)and(zx<=100000) then begin q1:=100000;i:=5;end
    else
      if (zx>100000)and(zx<=1000000) then begin q1:=1000000;i:=6;end;
    q2:=q1 mod zx;
    while (i<k) do
     begin
      if (q2=0)or(q2=10) then break;
      inc(i);
      q2:=(q2*10) mod zx;
     end;

    if (q2=0)or(q2=10) then while k>=i do k:=k-i;
    if k=0 then print(x);
    if k<7 then
     begin
      q:=1;
      for i:=1 to k do
      q:=q*10;
      qw:=q mod zx;
      ans:=x;
      for i:=1 to qw do
       ans:=(ans+m) mod n;
      print(ans);
     end
    else
     work;
  end;
end.
