var i,j,l,r,k,p,max:longint;
    n:char;
    a,c:array[1..100000] of char;
    b:array[1..100000] of longint;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  repeat
  begin
      read(n);
      inc(j);
      a[j]:=n;
  end;
  until ord(n)<32;
  a[j]:=' ';k:=1;
  for i:=1 to j-1 do
      if (a[i]<>'*') and (a[i]<>'+') then
         b[k]:=b[k]*10+(ord(a[i])-48) else
         begin
           inc(p);
           if a[i]='*' then
              c[p]:='*' else c[p]:='+';
           inc(k);
         end;
  for i:=1 to p do
    if c[i]='*' then
    begin
      b[i+1]:=b[i]*b[i+1];
      b[i]:=0;
    end;
  for i:=1 to k do
        max:=max+b[i];
  while max>10000 do
    max:=max mod 10000;
  write(max);
  close(input);
  close(output);
end.
