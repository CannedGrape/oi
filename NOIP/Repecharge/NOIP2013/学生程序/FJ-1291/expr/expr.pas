program expr;
var
  a,b,c,d:string;
  x,k,y,s,p,q:longint;
  r:array[1..200000]of string;
  t:array[1..200000]of int64;
procedure init;
begin
  readln(a);
end;
procedure make;
var
  i,j:longint;
begin
  j:=1;
  i:=1;
  repeat
    k:=i-1;
    while ('0'<=a[j]) and (a[j]<='9') do
      inc(j);
    val(copy(a,i,j-i),t[p]);
    inc(p);
    i:=j+1;
    r[q]:=a[j];
    inc(q);
    j:=i+1;
  until ord(a[i])=0;
end;
procedure made;
var
  i,j,k:longint;
begin
  for i:=1 to q-1 do
    if r[i]='*' then t[i+1]:=t[i]*t[i+1];
  for j:=1 to q-1 do
    if r[j]='+' then
    begin
      k:=j+1;
      while r[k]='*' do inc(k);
      t[k]:=t[j]+t[k];
    end;
end;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  p:=1;
  s:=0;
  q:=1;
  init;
  make;
  made;
  str(t[q-1],c);
  y:=1;
  d:=copy(c,length(c)-3,4);
  while d[y]='0' do inc(y);
  write(copy(d,y,4-y+1));
  close(input);
  close(output);
end.
