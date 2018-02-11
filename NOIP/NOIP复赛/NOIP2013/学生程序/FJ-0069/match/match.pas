const mo=99999997;
var i,j,n,k,mm:longint;
    a,f2,f1,num1,num2:array[0..1000010]of longint;
    ans:int64;
procedure swap(x,y:longint);
var m:longint;
begin
  m:=f2[x];f2[x]:=f2[y];f2[y]:=m;
end;
procedure qsort(l,r:longint);
var i,j,m,x:longint;
begin
  i:=l;j:=r;x:=a[(l+r)div 2];
  while i<j do
  begin
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
    begin
      m:=a[i];a[i]:=a[j];a[j]:=m;
      m:=f1[i];f1[i]:=f1[j];f1[j]:=m;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;
procedure qsort1(l,r:longint);
var i,j,m,x:longint;
begin
  i:=l;j:=r;x:=a[(l+r)div 2];
  while i<j do
  begin
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
    begin
      m:=a[i];a[i]:=a[j];a[j]:=m;
      m:=f2[i];f2[i]:=f2[j];f2[j]:=m;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsort1(i,r);
  if l<j then qsort1(l,j);
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    f1[i]:=i;
  end;
  qsort(1,n);
  for i:=1 to n do
  begin
    read(a[i]);
    f2[i]:=i;
  end;
  qsort1(1,n);
  for i:=1 to n do
  begin
    num1[f1[i]]:=i;
    num2[f2[i]]:=i;
  end;
  for i:=1 to n do
  begin
    if num1[i]<>num2[i] then
    begin
      for j:=1 to n do
      if num1[i]=num2[j] then
      begin
        if i<j then
        begin
         mm:=num2[j];
         for k:=j downto i+1 do
           num2[k]:=num2[k-1];
         num2[i]:=mm;
        end else
        begin
          mm:=num2[i];
          for k:=i downto j+1 do
            num2[k]:=num2[k-1];
          num2[j]:=mm;
        end;
        ans:=(ans+abs(i-j))mod mo;
        break;
      end;
    end;
  end;
  writeln(ans);
  close(input);close(output);
end.