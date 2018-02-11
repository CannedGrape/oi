program match;
type arr=array[1..100000,1..2]of longint;
var i,j,n,m,k,l,ans,x:longint;
    a,b:arr;
    c:array[1..100000]of longint;
procedure sort(l,r:longint;var a:arr);
var i,j,x,z:longint;
    y:array[1..2]of longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r)div 2,1];
  z:=a[(l+r)div 2,2];
  repeat
    while (a[i,1]<x)or((a[i,1]=x)and(a[i,2]<z))do inc(i);
    while (a[j,1]>x)or((a[j,1]=x)and(a[j,2]>Z))do dec(j);
    if not(i>j)then
    begin
      y:=a[i];
      a[i]:=a[j];
      a[j]:=y;
      i:=i+1;
      j:=j-1;
    end;
  until i>j;
  if i<r then sort(i,r,a);
  if j>l then sort(l,j,a);
end;
begin
assign(input,'match.in');reset(input);
assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do begin read(a[i,1]);a[i,2]:=i;end;readln;
  for i:=1 to n do begin read(b[i,1]);b[i,2]:=i;end;
  sort(1,n,a);
  sort(1,n,b);
  for i:=1 to n do c[b[i,2]]:=i;
  for i:=1 to n do
  if a[i,2]<>b[i,2]then
  begin
    j:=c[a[i,2]];
    if j>i then
    begin
      x:=b[j,2];
      for k:=j downto i+1 do
       begin
         b[k,2]:=b[k-1,2];
         c[b[k,2]]:=k;
         ans:=ans+1;
       end;
      b[i,2]:=x;c[b[i,2]]:=j;
    end;
    if j<i then
    begin
      x:=b[j,2];
      for k:=i-1 downto j do
       begin
         b[k,2]:=b[k+1,2];
         c[b[k,2]]:=k;
         ans:=ans+1;
       end;
      b[i,2]:=x;c[b[i,2]]:=j;
    end;

  end;
  write(ans);
close(input);close(output);
end.