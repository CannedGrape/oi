type arr=array[1..1000000] of longint;
var  n,i,j,t,ans,x,y1,y2:longint;
     a,b,k1,k2:arr;

procedure qsort1(l,r:longint);
var i,j,mid,t:longint;
begin
  i:=l;j:=r;mid:=a[(l+r) div 2];
  repeat
    while a[i]>mid do inc(i);
    while a[j]<mid do dec(j);
    if i<=j then
    begin
      t:=a[i];a[i]:=a[j];a[j]:=t;
      t:=k1[i];k1[i]:=k1[j];k1[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsort1(l,j);
  if i<r then qsort1(i,r);
end;

procedure qsort2(l,r:longint);
var i,j,mid,t:longint;
begin
  i:=l;j:=r;mid:=b[(l+r) div 2];
  repeat
    while b[i]>mid do inc(i);
    while b[j]<mid do dec(j);
    if i<=j then
    begin
      t:=b[i];b[i]:=b[j];b[j]:=t;
      t:=k2[i];k2[i]:=k2[j];k2[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsort2(l,j);
  if i<r then qsort2(i,r);
end;

begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do begin read(a[i]);k1[i]:=i; end;
  readln;
  for i:=1 to n do begin read(b[i]);k2[i]:=i; end;
  qsort1(1,n);qsort2(1,n);
  ans:=0;for i:=1 to n do a[i]:=i;
  for i:=1 to n do
    if k1[i]<>k2[i] then
    begin
      x:=i;y2:=k2[i];
      repeat
        y1:=a[y2];
        y2:=k2[y1];
        t:=k1[y1];k1[y1]:=k1[y2];k1[y2]:=t;
        inc(ans);
      until y2=x;
    end;
  writeln(ans-1);
  close(input);close(output);
end.

