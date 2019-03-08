Program match;
Var
  a:array[0..1000,1..2] of longint;
  i,j,k,n:longint;

  trueans,ans,m:qword;

Procedure qsort(l,r:longint);
var
  i,j,mid,q,p:longint;
begin
  i:=l;j:=r;mid:=a[(l+r) div 2,1];
  repeat
    while a[i,1]<mid do inc(i);
    while a[j,1]>mid do dec(j);
    if i<=j then begin
      q:=a[i,1];p:=a[i,2];
      a[i,1]:=a[j,1];
      a[i,2]:=a[j,2];
      a[j,1]:=q;
      a[j,2]:=p;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;


Begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  trueans:=1;

  readln(n);
  for i:=1 to n do read(a[i,1]);
  for i:=1 to n do read(a[i,2]);

  qsort(1,n);

  {ans:=fenzhi(1,n);}

  for i:=1 to n do
    for j:= i+1 to n do
      if a[i,2]>a[j,2] then inc(ans);


  m:=ans;

  for i:=1 to ans do begin
    trueans:=trueans*m;
    dec(m);
  end;

  trueans:=trueans  mod 99999997;

  writeln(trueans);

  close(input);close(output);

End.
