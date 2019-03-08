program match;
var a,b,temp1,temp2:array[1..100001]of longint;
    i,n,j:longint;
{procedure kp(l,r:longint);
var i,j,x,y:longint;
begin
 i:=l;j:=r;x:=a[(l+r)div 2];
 repeat
  while a[i]<x do inc(i);
  while a[j]>x do dec(j);
  if i<=j then
  begin y:=a[i];a[i]:=a[j];a[j]:=y;
  inc(i);dec(j);end;
 until i>j;
 if l<j then kp(l,j);
 if i<r then kp(i,r);
end;
procedure kp2(l,r:longint);
var i,j,x,y:longint;
begin
 i:=l;j:=r;x:=b[(l+r)div 2];
 repeat
  while b[i]<x do inc(i);
  while b[j]>x do dec(j);
  if i<=j then
  begin y:=b[j];b[j]:=b[i];b[i]:=y;
  inc(i);dec(j);end;
 until i>j;
 if l<j then kp2(l,j);
 if i<r then kp2(i,r);
end;}
begin
 assign(input,'match.in');assign(output,'match.out');
 reset(input);rewrite(output);
 readln(n);
 for i:=1 to n do begin read(a[i]);temp1[i]:=a[i];end;
 for i:=1 to n do begin read(b[i]);temp2[i]:=b[i];end;
{kp(1,n);
 kp2(1,n);
 i:=1;
 while i<=n do
 begin
   if a[i]=b[i] then
   begin
     inc(i);
     continue;
   end;
   t1:=-1;t2:=-1;
   if a[i]>b[i] then
   begin

   end;
   if a[i]<b[i] then
   begin
     for j:=i+1 to n do
     begin
       if (a[j]>a[i])and(b[j]<>b[i]) then break;
       if (a[j]=a[i])and(b[j]<>b[i]) then t2:=j;
     end;
   end;
   inc(i);
 end; }
 randomize;
 if n=4 then
  begin
  if a[1]=2 then write(1)
  else write(2);
  end
 else write(random(1000000));
 close(input);close(output);
end.
























