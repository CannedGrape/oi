type point=record
             num,wz:longint;
           end;
const p=99999997;
var n:longint;
    a,b:array[0..100001] of point;
    expe,rea:array[0..100001] of longint;
procedure init;
var i:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i].num); readln;
  for i:=1 to n do read(b[i].num); readln;
  for i:=1 to n do begin a[i].wz:=i; b[i].wz:=i; end;
end;
procedure qsorta(l,r:longint);
var i,j:longint;
    t:point;
begin
  i:=l; j:=r; t:=a[i];
  while i<j do
  begin
    while (i<j) and (t.num>=a[j].num) do j:=j-1;
    if i<j then begin a[i]:=a[j]; i:=i+1; end;
    while (i<j) and (t.num<=a[i].num) do i:=i+1;
    if i<j then begin a[j]:=a[i]; j:=j-1; end;
  end;
  a[i]:=t; i:=i+1; j:=j-1;
  if l<j then qsorta(l,j);
  if i<r then qsorta(i,r);
end;
procedure qsortb(l,r:longint);
var i,j:longint;
    t:point;
begin
  i:=l; j:=r; t:=b[i];
  while i<j do
  begin
    while (i<j) and (t.num>=b[j].num) do j:=j-1;
    if i<j then begin b[i]:=b[j]; i:=i+1; end;
    while (i<j) and (t.num<=b[i].num) do i:=i+1;
    if i<j then begin b[j]:=b[i]; j:=j-1; end;
  end;
  b[i]:=t; i:=i+1; j:=j-1;
  if l<j then qsortb(l,j);
  if i<r then qsortb(i,r);
end;
procedure compare;
var i:longint;
begin
  for i:=1 to n do expe[b[i].wz]:=a[i].num;
  for i:=1 to n do rea[a[i].wz]:=a[i].num;
end;
procedure calc;
var i,j,k,tmp:longint;
    ans:longint;
begin
  ans:=0;
  for i:=1 to n do
  begin
    if expe[i]<>rea[i] then
    begin
      j:=n;
      while rea[j]<>expe[i] do j:=j-1;
      for k:=j downto i+1 do
      begin
        tmp:=rea[k]; rea[k]:=rea[k-1]; rea[k-1]:=tmp;
        ans:=(ans+1) mod p;
      end;
    end;
  end;
  writeln(ans);
end;
begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  init;
  qsorta(1,n);
  qsortb(1,n);
  compare;
  calc;
  close(input);
  close(output);
end.