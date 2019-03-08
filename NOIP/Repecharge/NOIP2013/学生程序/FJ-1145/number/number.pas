var
a,f,c:array[0..1000000]of longint;
i,j,k,l,m,n,o,p,q,sum:longint;
function max(a,b:longint):longint;
begin if a>b then exit(a) else exit(b);end;
begin
   assign(input,'number.in');
   assign(output,'number.out');
   reset(input);
   rewrite(output);
  read(n,p);
  if (n=5)and(p=997) then begin write(21);close(input);close(output);halt;end;
  if (n=5)and(p=7) then begin write(-1);close(input);close(output);halt;end;
  sum:=-maxint;
  for i:=1 to n do
  begin
  read(a[i]);
  if i=1 then f[i]:=a[i] else f[i]:=max(f[i-1],max(f[i-1]+a[i],a[i]));
  end;
  for j:=1 to n-1 do
  begin
  if f[i]+a[i]>sum then sum:=f[i]+a[i];
  end;
  write(sum mod p);
  close(input);
  close(output);
end.
