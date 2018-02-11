var i,j,k,m,n,o,p,q,l,sum,tmp,max,min:longint;
    a,b,c:array[0..1000000] of longint;
    bo,lian:boolean;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  read(n,p);
  sum:=-maxlongint;
  for i:=1 to n do c[i]:=-maxlongint;
  for i:=1 to n do begin
    read(a[i]);
    if i=1 then begin
      if a[i]>0 then b[i]:=a[i] mod p else begin
      b[i]:=(abs(a[i]) mod p)*(-1);inc(q);end;
      continue;
    end;
    if a[i-1]>0 then begin
      if a[i]>=0 then b[i]:=(a[i] mod p+b[i-1]) mod p
      else b[i]:=b[i-1];
    end
    else begin
      if a[i] mod p>b[i-1] then b[i]:=a[i] mod p
      else b[i]:=b[i-1];
    end;
    if a[i]<0 then inc(q);
  end;
  c[1]:=b[1];
  if q=n then min:=((abs(c[1]) mod p+abs(b[1])) mod p)*(-1);
  if c[1]>sum then sum:=c[1];
  if q<n then
  for i:=2 to n do begin
    c[i]:=(c[i-1] mod p+b[i-1])mod p;
    if c[i]>sum then sum:=c[i];
  end else
  for i:=2 to n do begin
    c[i]:=min;
    if c[i]+b[i]<0 then o:=((abs(c[i]) mod p+abs(b[i])) mod p)*(-1)
    else o:=((abs(c[i]) mod p+abs(b[i])) mod p);
    if o>min then min:=o;
    if c[i]>sum then sum:=c[i];
  end;
  if sum<0 then begin write('-',abs(sum)mod p);end
  else write(sum mod p);
  close(input);
  close(output);
end.