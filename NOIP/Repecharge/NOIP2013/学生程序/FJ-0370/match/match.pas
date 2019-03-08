program match;
var
  n,k,i,j,x,y:longint;
  ans:int64;
  a,b,r,a1,b1,r1,c:array[0..100000] of longint;
  d:array[0..100000] of boolean;
procedure kb(s,t:longint);
var
  m,i,j:longint;
begin
  if s=t then exit;
  m:=(s+t) >> 1;
  kb(s,m);
  kb(m+1,t);
  i:=s;
  j:=m+1;
  k:=s;
  while (i<=m) and (j<=t) do
  begin
    if a[i]<a[j] then
    begin
      r[k]:=a[i]; r1[k]:=a1[i]; inc(i); inc(k);
    end
    else begin
      r[k]:=a[j]; r1[k]:=a1[j]; inc(j); inc(k);
      end;
  end;
  while i<=m do
    begin
      r[k]:=a[i]; r1[k]:=a1[i]; inc(i); inc(k);
    end;
  while j<=t do
    begin
      r[k]:=a[j]; r1[k]:=a1[j]; inc(j); inc(k);
    end;
  for i:=s to t do
  begin
    a[i]:=r[i];
    a1[i]:=r1[i];
  end;
end;
procedure kb2(s,t:longint);
var
  m,i,j:longint;
begin
  if s=t then exit;
  m:=(s+t) >> 1;
  kb2(s,m);
  kb2(m+1,t);
  i:=s;
  j:=m+1;
  k:=s;
  while (i<=m) and (j<=t) do
  begin
    if b[i]<b[j] then
    begin
      r[k]:=b[i]; r1[k]:=b1[i]; inc(i); inc(k);
    end
    else begin
      r[k]:=b[j]; r1[k]:=b1[j]; inc(j); inc(k);
      end;
  end;
  while i<=m do
    begin
      r[k]:=b[i]; r1[k]:=b1[i]; inc(i); inc(k);
    end;
  while j<=t do
    begin
      r[k]:=b[j]; r1[k]:=b1[j]; inc(j); inc(k);
    end;
  for i:=s to t do
  begin
    b[i]:=r[i];
    b1[i]:=r1[i];
  end;
end;
begin
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);

    a1[i]:=i;
  end;
  for i:=1 to n do
  begin
    read(b[i]);

    b1[i]:=i;
  end;
  kb(1,n);
  kb2(1,n);
  for i:=1 to n do
  begin
    c[a1[i]]:=b1[i];
  end;
  ans:=0;
  {  for i:=1 to n do
      writeln(i,' ',c[i]);}
  for i:=1 to n do
  begin
    if i=c[i] then begin d[i]:=true; end
    else
    if not d[i] then
      begin
        j:=0;
        x:=i;
        y:=c[i];
        while i<>y do
        begin
          d[x]:=true; //writeln('/',x);
          x:=y;
          y:=c[y];
          inc(j);
        end;
          d[x]:=true; //writeln('/',x);
      ans:=ans+j;
      if ans>99999997 then
        ans:=ans mod 99999997;
      //writeln(i,' ',ans);
      end;
  end;
  writeln(ans);
  close(input); close(output);
end.
