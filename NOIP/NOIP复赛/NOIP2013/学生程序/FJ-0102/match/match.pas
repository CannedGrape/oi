var n,m,i,j,ans:longint;
    a,b,ap,bp:array[0..1000000]of longint;
    //ap final position

procedure swap(var a,b:longint);
var k:longint;
begin
 k:=a;a:=b;b:=k;
end;

procedure sort1(l,r:longint);
var i,j,k:longint;
begin
 i:=l;j:=r;k:=a[(i+j)div 2];
 repeat
  while a[i]<k do inc(i);
  while a[j]>k do dec(j);
  if i<=j then
   begin
    swap(a[i],a[j]);
    swap(ap[i],ap[j]);
    inc(i);dec(j);
   end;
 until i>j;
 if l<j then sort1(l,j);
 if i<r then sort1(i,r);
end;

procedure sort2(l,r:longint);
var i,j,k:longint;
begin
 i:=l;j:=r;k:=b[(i+j)div 2];
 repeat
  while b[i]<k do inc(i);
  while b[j]>k do dec(j);
  if i<=j then
   begin
    swap(b[i],b[j]);
    swap(bp[i],bp[j]);
    inc(i);dec(j);
   end;
 until i>j;
 if l<j then sort2(l,j);
 if i<r then sort2(i,r);
end;


procedure cal;
var i,j,temp:longint;
begin
 for i:=1 to n do if ap[i]<>bp[i] then
  begin
   temp:=bp[i];
   for j:=i+1 to n do
    if temp<>ap[i] then
     begin
      inc(ans);
      swap(bp[j],temp)
     end
    else break;
  end;
end;


begin

 assign(input,'match.in');
 assign(output,'match.out');
 reset(input);
 rewrite(output);
 read(n);
 ans:=0;
 for i:=1 to n do read(a[i]);
 for i:=1 to n do read(b[i]);
 for i:=1 to n do
  begin
   ap[i]:=i;bp[i]:=i;
  end;
 sort1(1,n);sort2(1,n);
 cal;
 writeln(ans mod 99999997);
 close(input);
 close(output);
end.
