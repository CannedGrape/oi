program block;
type ar=array[1..100000]of longint;
var n,i,k,t:longint;
    flag:boolean;
    f1,f2:text;
    a,r:ar;
procedure kp(a,b:longint;var r:ar);
var i,j,mid,tem:longint;
begin
i:=a;j:=b;mid:=r[(a+b)div 2];
repeat
while r[i]<=mid do inc(i);
while r[j]>=mid do dec(j);
if i<=j then
begin
tem:=r[i];r[i]:=r[j];r[j]:=tem;
end;
inc(i);dec(j);
until i>j;
if i<b then kp(i,b,r);
if j>a then kp(a,j,r);

end;
begin
assign(f1,'block.in');reset(f1);
  assign(f2,'block.out');rewrite(f2);
  readln(n);
  for i:=1 to n do
read(a[i]);
k:=0;
  repeat
  r:=a;kp(1,n,r);
  t:=r[1];;flag:=true;
 while i<=n do

if a[i]-t>=0 then
 begin
a[i]:=a[i]-t;
flag:=false;
inc(i);
end
  else inc(i);
  inc(k);
  until flag;
  writeln(k);
  close(f1);close(f2);
  end.


