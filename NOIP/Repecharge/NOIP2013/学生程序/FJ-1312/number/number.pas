program number;
  var
    n,p:longint;
    i,j,k:longint;
    a:array[1..1000000] of longint;
    b:array[1..1000000] of longint;
    c:array[1..1000000] of longint;
    s,m,t,q,o:longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
  read(a[i]);
  b[1]:=a[1];
  for i:=2 to n do
  begin
    s:=0;
    j:=i;
    k:=i;
    o:=i;
    repeat
      if a[o]>0 then s:=s+a[o];
      o:=o-1;
    until o<1;
    j:=j-1;
    if s=0 then
           repeat
             if (a[j]<0) and (a[j]<a[j+1]) then s:=a[j]
                                           else s:=a[j+1];
             j:=j-1;
           until j<1;
    b[k]:=s;
  end;
  m:=0;
  c[1]:=b[1];
  for i:=2 to n do
  begin
    j:=i;
    repeat
      m:=m+a[j-1]+b[j-1];
      j:=j-1;
    until i=0;
  end;
  for i:=1 to n-1 do
  for j:=i+1 to n do
  if c[i]<c[j] then
               begin
               t:=c[i];
               c[i]:=c[j];
               c[j]:=t;
               end;
  q:=c[1] mod p;
  writeln(q);
  close(input);
  close(output);
end.
