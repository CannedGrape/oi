var
  a,b,c:array[1..1000000]of longint;
  n,i,p,j,t:longint;
function dk(q,m:longint):longint;
var
  i:longint;
begin
  for i:=q to m do
    for j:=q to i-1 do
    if a[j]>a[i] then begin
     t:=a[j]; a[j]:=a[i]; a[i]:=t; end;
  dk:=a[m];
end;
function lich(l,ll:longint):longint;
var
  txt,txtt:longint;
begin
  txt:=a[l]; if l=ll then begin lich:=a[1]; exit; end;
  for i:=l+1 to ll do
    if txt+a[i]>=txt then txt:=txt+a[i]
     else txt:=0;
  if txt=0 then txt:=-maxint;
  txtt:=dk(l,ll);
  if txt>txtt then lich:=txt
   else lich:=txtt;
end;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    b[i]:=lich(1,i);
  c[1]:=b[1];
  for i:=2 to n do
    c[i]:=c[i-1]+b[i-1];
  for i:=1 to n do
    for j:=1 to i-1 do
    if c[j]>c[i] then begin
     t:=c[j]; c[j]:=c[i]; c[i]:=t; end;
  writeln(c[n] mod p);
  close(input);
  close(output);
end.