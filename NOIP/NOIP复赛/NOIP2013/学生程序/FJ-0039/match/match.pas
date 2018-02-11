var i,j,n,ans,k,h:longint;
friendzhi,friend,qa,a,aa,qb,b,bb:array[1..100000]of longint;
procedure sort1(l,r: longint);
var
  i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
  while a[i]<x do
    inc(i);
    while x<a[j] do
     dec(j);
     if not(i>j) then
      begin
         y:=a[i];
         a[i]:=a[j];
         a[j]:=y;
         y:=qa[i];
         qa[i]:=qa[j];
         qa[j]:=y;
         inc(i);
         j:=j-1;
      end;
      until i>j;
    if l<j then
           sort1(l,j);
    if i<r then
           sort1(i,r);
end;
procedure sort2(l,r: longint);
var
  i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=b[(l+r) div 2];
  repeat
  while b[i]<x do
    inc(i);
    while x<b[j] do
     dec(j);
     if not(i>j) then
      begin
         y:=b[i];
         b[i]:=b[j];
         b[j]:=y;
         y:=qb[i];
         qb[i]:=qb[j];
         qb[j]:=y;
         inc(i);
         j:=j-1;
      end;
      until i>j;
    if l<j then
           sort2(l,j);
    if i<r then
           sort2(i,r);
end;

begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    aa[i]:=a[i];
    qa[i]:=i;
  end;
  for i:=1 to n do
  begin
    read(b[i]);
    bb[i]:=b[i];
    qb[i]:=i;
  end;
  sort1(1,n);
  sort2(1,n);
  for i:=n downto 1 do
  for j:=1 to n do
   if b[j]=bb[i] then
   begin
     friend[i]:=qa[j];
     friendzhi[i]:=aa[qa[j]];
   end;
  ans:=0;
  for i:=n downto 1 do
  begin
    for j:=(friend[i]+1) to i do
    begin
      h:=aa[j];
      aa[j]:=aa[j-1];
      aa[j-1]:=h;
      inc(ans);
    end;
    for j:=i-1 downto 1 do
    for k:=1 to n do
    begin
      if aa[k]=friendzhi[j] then friend[j]:=k;
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.






