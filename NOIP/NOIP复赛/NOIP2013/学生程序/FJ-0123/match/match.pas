var n,i,j,m,tot,l,r,mid:longint;
    a,b,c,d,f,v:array [0..200000] of longint;
    ans,sum:int64;
procedure work(p1,p2:longint);
var v1,v2,v3,v4:longint;
begin
  v1:=p1;v2:=p2;v3:=a[(p1+p2)div 2];
  repeat
    while a[v1]<v3 do inc(v1);
    while a[v2]>v3 do dec(v2);
    if v1<=v2 then
    begin
      v4:=a[v1];a[v1]:=a[v2];a[v2]:=v4;
      v4:=c[v1];c[v1]:=c[v2];c[v2]:=v4;
      inc(v1);dec(v2);
    end
  until v1>v2;
  if v1<p2 then work(v1,p2);
  if p1<v2 then work(p1,v2);
end;
procedure work1(p1,p2:longint);
var v1,v2,v3,v4:longint;
begin
  v1:=p1;v2:=p2;v3:=b[(p1+p2)div 2];
  repeat
    while b[v1]<v3 do inc(v1);
    while b[v2]>v3 do dec(v2);
    if v1<=v2 then
    begin
      v4:=b[v1];b[v1]:=b[v2];b[v2]:=v4;
      v4:=d[v1];d[v1]:=d[v2];d[v2]:=v4;
      inc(v1);dec(v2);
    end
  until v1>v2;
  if v1<p2 then work1(v1,p2);
  if p1<v2 then work1(p1,v2);
end;
begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    c[i]:=i;
  end;
  readln;
  for i:=1 to n do
  begin
    read(b[i]);
    d[i]:=i;
  end;
  work(1,n);
  work1(1,n);
  for i:=1 to n do
    v[c[i]]:=d[i];
  for i:=1 to n do
  begin
    sum:=0;
    for j:=1 to i do
    if v[j]<=v[i] then inc(sum);
    sum:=i-sum;
    ans:=(ans+sum)mod 99999997;
  end;
  writeln(ans);
  close(input);
  close(output);
end.




