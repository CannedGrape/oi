var
  i,j,m,n,k,l,r,x:longint;
  a,f:array [0..1000000] of longint;
begin
  assign(input,'circle.in');reset(input);assign(output,'circle.out');rewrite(output);
  read(n,m,k,x);
  filldword(a,n+1,0);
  filldword(f,n+1,0);
  f[0]:=1;
  for i:=1 to k do
  begin
    f[i]:=f[i-1]*10 mod n;
    r:=i;
    if a[f[i]]>0 then break;
    a[f[i]]:=i;
  end;
  l:=x;
  if r<k then
  begin
    dec(k,a[f[r]]);k:=k mod (r-a[f[r]]);
    inc(k,a[f[r]]);
  end;
  l:=(l+int64(m)*f[k] mod n) mod n;
  writeln(l);
  close(input);close(output);
end.
