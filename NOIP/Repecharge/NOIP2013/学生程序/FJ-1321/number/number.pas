program number;
var b,c:array[1..1000000]of longint;
    a,i,j,k,l,n,m1,m2,m3,m4,p:longint;
    f1,f2:text;
begin
  assign(f1,'number.in');
  assign(f2,'number.out');
  reset(f1);
  rewrite(f2);
  read(f1,n,p);
  read(f1,a);
  b[1]:=a;
  c[1]:=a;
  l:=a;
  m1:=0;
  m2:=0;
  m3:=0;
  for i:=2 to n do
   begin
    read(f1,a);
    b[i]:=a+l;
    l:=a+l;
    for j:=1 to i do
     begin
      if m1<b[j] then m1:=b[j];
      if m2<c[j] then m2:=c[j];
     end;
    c[i]:=m1+m2;
   end;
   m3:=0;
   for i:=1 to n do if c[i]>m3 then m3:=c[i];
  write(f2,m3 mod p);
  close(f1);
  close(f2);
  end.

