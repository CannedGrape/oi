const p=99999997;
type arr=array[0..100000]of int64;
    aarr=array[0..100000]of longint;
var
  a,b:array[0..100000]of int64;
  da,db:array[0..100000]of longint;
  n,i,j,xx,yy,ans:longint;  t:int64;
procedure kp(l,r:longint);
var i,j:longint; t,mid:int64;
begin
  i:=l;j:=r;
  mid:=a[(i+j)div 2];
  repeat
   while a[i]<mid do inc(i);
   while a[j]>mid do dec(j);
   if i<=j then
    begin
     t:=a[i];a[i]:=a[j];a[j]:=t;
     t:=da[i];da[i]:=da[j];da[j]:=t;
     inc(i);dec(j);
    end;
  until i>j;
  if i<r then kp(i,r);
  if l<j then kp(l,j);
end;
procedure kpp(l,r:longint);
var i,j:longint; t,mid:int64;
begin
  i:=l;j:=r;
  mid:=b[(i+j)div 2];
  repeat
   while b[i]<mid do inc(i);
   while b[j]>mid do dec(j);
   if i<=j then
    begin
     t:=b[i];b[i]:=b[j];b[j]:=t;
     t:=db[i];db[i]:=db[j];db[j]:=t;
     inc(i);dec(j);
    end;
  until i>j;
  if i<r then kp(i,r);
  if l<j then kp(l,j);
end;
begin
  readln(n);
  for i:=1 to n do
   begin read(a[i]);da[i]:=i;end;
   //aa:=a;
  for i:=1 to n do
   begin read(b[i]);db[i]:=i;end;
   //bb:=b;
  kp(1,n);
  kpp(1,n);
  //l:=0;r:=n+1;

  for i:=1 to n do
   begin
    if da[i]=db[i] then continue;
       xx:=da[i];yy:=db[i];
                writeln(xx,yy);
    if da[i]-i<=db[i]-i then
     for j:=xx downto i do
      begin t:=da[j];da[j]:=da[j-1];da[j-1]:=t;ans:=(ans+1)mod p;end
  else
     for j:=yy downto i do
      begin t:=db[j];db[j]:=db[j-1];db[j-1]:=t;ans:=(ans+1)mod p;end;
   end;
  writeln(ans);
end.
