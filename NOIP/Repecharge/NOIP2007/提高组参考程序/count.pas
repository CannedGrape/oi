program count;
var a:array[0..200000] of longint;
    now,i,n:longint;
procedure qsort(l,r:longint);
var x,y,i,j:longint;
begin
  if l>=r then exit;
  x:=a[(l+r) shr 1];
  i:=l; j:=r;
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then begin
       y:=a[i]; a[i]:=a[j]; a[j]:=y;
       inc(i);
       dec(j);
    end;
  until i>j;
  qsort(l,j);
  qsort(i,r);
end;
begin
  assign(input,'count.in'); reset(input);
  assign(output,'count.out'); rewrite(output);
  readln(n);
  for i:=1 to n do 
     readln(a[i]);
  qsort(1,n);
  a[0]:=-1;  now:=0;
  for i:=1 to n do begin
     if a[i]<>a[i-1] then begin
       if now <> 0 then writeln(now);
       write(a[i],' ');
       now:=0;
     end;
     inc(now);
  end;
  writeln(now);
  close(input); close(output);
end.
