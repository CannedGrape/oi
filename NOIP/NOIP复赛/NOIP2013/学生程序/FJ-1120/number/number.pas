var
  a,l,f:array[0..1000000] of longint;
  i,n,ma,p,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,p);
  ma:=-maxlongint;
  for i:=1 to n do
    begin
      read(a[i]);
      l[i]:=max(l[i-1]+a[i],a[i]);
      l[i]:=l[i] mod p;
      ma:=max(l[i],ma);
      f[i]:=ma;
    end;
  readln;
  l[1]:=f[1];
  ma:=(f[1]+l[1]) mod p;
  ans:=l[1];
  for i:=2 to n do
    begin
      l[i]:=ma;
      ans:=max(l[i],ans);
      ans:=ans mod p;
      ma:=max(l[i]+f[i],ma);
      ma:=ma mod p;
    end;
  writeln(ans mod p);
  close(input); close(output);
end.
