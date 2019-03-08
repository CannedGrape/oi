var s:ansistring;
    len,i,e,f,l,r,d:longint;
    a:array[1..1000001] of longint;
    b:array[1..1000000] of char;
    c:array[1..1000001] of string;
begin
  readln(s);
  len:=length(s);
  l:=1;r:=1;d:=1;
  for i:=1 to len do
   begin
    if (s[i]<>'+') or (s[i]<>'*') then r:=r+1
    else
     begin
      c[d]:=copy(s,l,r);
      l:=r+2;
      r:=r+2;
      b[d]:=s[r+1];
      inc(d);
     end;
    if i=len then c[d]:=copy(s,l,r);
   end;
  for i:=1 to d do
    chl(c[i],a[i]);
  ans:=a[1];
  for i:=1 to d-1 do
    if (b[i]='+') and (b[i+1]='+') then ans:=ans+a[i+1]
    else if (b[i]='*') then ans:=ans+a[i]*a[i+1];
end.
