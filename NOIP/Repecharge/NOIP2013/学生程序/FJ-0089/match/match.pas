var
  i,j,m,p,t,n:longint;
  a:array[1..1000,1..1000] of longint;
procedure qsort(l,r:longint);
var
  i,j,mid,p:longint;
begin
  i:=l;j:=r;
  mid:=a[1,(l+r) div 2];
  repeat
    while a[1,i]<mid do inc(i);
    while a[1,j]>mid do dec(j);
    if i<=j then
    begin
      p:=a[1,i];a[1,i]:=a[1,j];a[1,j]:=p;
      p:=a[2,i];a[2,i]:=a[2,j];a[2,j]:=p;
      inc(i);dec(j);
    end;
  until i>=j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);

end;

begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to 2 do
    for j:=1 to n do
    begin
      read(a[i,j]);

    end;
  qsort(1,n);
  for i:=1 to n-1 do
    for j:=i+1 to n do
    begin
      if a[2,i]>a[2,j] then
      begin
        p:=a[2,i];a[2,i]:=a[2,j];a[2,j]:=p;
        inc(t);
      end;
    end;
  writeln(t);
  close(input);close(output);
end.