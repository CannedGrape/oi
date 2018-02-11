var a,b,la,lb,c,lla,llb,cc,ccc:array[0..100000]of longint;
    ans,i,tot,n,kk,kkk:longint;
procedure qsorta(l,r:longint);
var i,j,mid,t:longint;
begin
  i:=l;j:=r;mid:=(a[(l+r) div 2]);
  repeat
   while a[i]<mid do inc(i);
   while a[j]>mid do dec(j);
   if i<=j then
     begin
       t:=a[i];
       a[i]:=a[j];
       a[j]:=t;
       t:=la[i];
       la[i]:=la[j];
       la[j]:=t;
       inc(i);
       dec(j);
     end;
  until i>j;
  if i<r then qsorta(i,r);
  if l<j then qsorta(l,j);
end;
procedure qsortb(l,r:longint);
var i,j,mid,t:longint;
begin
  i:=l;j:=r;mid:=(b[(l+r) div 2]);
  repeat
   while b[i]<mid do inc(i);
   while b[j]>mid do dec(j);
   if i<=j then
     begin
       t:=b[i];
       b[i]:=b[j];
       b[j]:=t;
       t:=lb[i];
       lb[i]:=lb[j];
       lb[j]:=t;
       inc(i);
       dec(j);
     end;
  until i>j;
  if i<r then qsortb(i,r);
  if l<j then qsortb(l,j);
end;
procedure qsortc(l,r:longint);
var i,j,mid,t:longint;
begin
  i:=l;j:=r;mid:=(ccc[(l+r) div 2]);
  repeat
   while ccc[i]<mid do inc(i);
   while ccc[j]>mid do dec(j);
   if i<=j then
     begin
       t:=ccc[i];
       ccc[i]:=ccc[j];
       ccc[j]:=t;
       inc(ans);
       inc(i);
       dec(j);
     end;
  until i>j;
  if i<r then qsortc(i,r);
  if l<j then qsortc(l,j);
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);readln;
  for i:=1 to n do read(b[i]);readln;
  for i:=1 to n do
    begin
      la[i]:=i;
      lb[i]:=i;
    end;
  qsorta(1,n);
  qsortb(1,n);
  tot:=0;
  for i:=1 to n do
    if la[i]<>lb[i] then
      begin
        lla[i]:=la[i];
        llb[i]:=lb[i];
      end;
  for i:=1 to n do
  begin
    c[i]:=llb[i];
    cc[i]:=lla[i];
  end;
  ans:=0;
  for i:=1 to n do
    if ((c[i]<>i) and (c[i]<>0) and (c[c[i]]=i)) then
      begin
        inc(ans);
        kkk:=cc[i];
        kk:=c[i];
         c[kkk]:=0;
        c[kk]:=0;
     end;
  tot:=0;
  for i:=1 to n do
    if c[i]<>0 then
      begin
        inc(tot);
        ccc[tot]:=c[i];
      end;
  qsortc(1,tot);
  writeln(ans);
  close(input);close(output);
end.
