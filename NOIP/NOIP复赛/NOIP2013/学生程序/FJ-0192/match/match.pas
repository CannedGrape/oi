const Ln=100000+20;
      ndsl=99999997;
var l,r:array[0..Ln]of longint;
    p,a,b:array[0..Ln]of longint;
    d:array[0..1,0..Ln]of longint;
    n,m:longint;
//
Procedure qsort(l,r:longint);
  var i,j,m,t:longint;
  begin
    i:=l;j:=r;m:=a[(i+j)div 2];
    while i<=j do
    begin
      while a[i]<m do inc(i);
      while a[j]>m do dec(j);
      if i<=j then
      begin
        t:=a[i];a[i]:=a[j];a[j]:=t;
        t:=b[i];b[i]:=b[j];b[j]:=t;
        inc(i);dec(j);
      end;
    end;
    if l<j then qsort(l,j);
    if i<r then qsort(i,r);
  end;
//
Function calc(l,r,x:longint):int64;
  var mid,u,v,t:longint;
  begin
    if l=r then begin d[x][l]:=a[l]; exit(0); end;
    mid:=(l+r)div 2;
    calc:=(calc(l,mid,1-x)+calc(mid+1,r,1-x))mod ndsl;
    u:=l;v:=mid+1;t:=l-1;
    while (u<=mid)and(v<=r) do
      if d[1-x][u]>d[1-x][v] then
      begin calc:=calc+mid-u+1;
            inc(t);
            d[x][t]:=d[1-x][v];
            inc(v);
      end
      else begin
            inc(t);
            d[x][t]:=d[1-x][u];
            inc(u);
      end;
    while u<=mid do begin inc(t);d[x][t]:=d[1-x][u];inc(u);end;
    while v<=r   do begin inc(t);d[x][t]:=d[1-x][v];inc(v);end;
    calc:=calc mod ndsl;
  end;
//
Procedure Init;
  var i:longint;
  begin
    readln(n);
    for i:=1 to n do read(l[i]);
    for i:=1 to n do read(r[i]);
  end;
//
Procedure sort;
  var i:longint;
  begin
    for i:=1 to n do b[i]:=i;
    qsort(1,n);
  end;
//
Procedure Prepare;
  var i:longint;
  begin
    for i:=1 to n do a[i]:=l[i]; sort;
    for i:=1 to n do p[i]:=b[i];
    for i:=1 to n do a[i]:=r[i]; sort;
    for i:=1 to n do a[p[i]]:=b[i];
  end;
//
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  //
  Init;
  Prepare;
  writeln(calc(1,n,0));
  //
  close(input);close(output);
end.