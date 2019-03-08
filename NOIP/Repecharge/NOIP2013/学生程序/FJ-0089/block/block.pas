var
  a,b:array[0..100001]of longint;
  i,j,x,m,n,t:longint;
procedure qsort(l,r:longint);
var
  i,j,mid,p:longint;
begin
  i:=l;j:=r;
  mid:=a[(l+r)div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
    begin
      p:=a[i];a[i]:=a[j];a[j]:=p;
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
  begin
    read(b[i]);
    a[i]:=b[i];
  end;
  qsort(1,n);a[n+1]:=0;
  t:=a[1]; j:=1;
  repeat
    inc(j);x:=0; m:=0;
    if a[j]>a[j-1] then
    begin
      for i:=1 to n+1 do
      begin
        if b[i]>=a[j] then inc(m)
        else if m>0 then
        begin
          inc(x);m:=0;
        end;
      end;
      if x<>0 then
      t:=t+(a[j]-a[j-1])*x;
    end;
  until j=n;
  writeln(t);
  close(input);close(output);
end.
