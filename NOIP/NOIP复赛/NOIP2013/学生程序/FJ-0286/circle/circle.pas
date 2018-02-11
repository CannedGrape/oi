var a:array[0..10000000] of longint;
    n,m,k,l,x,s:int64;
procedure mi(t:int64);
begin
  if t=1 then exit;
  mi(t div 2);s:=s*s mod l;
  if t mod 2=1 then s:=s*10 mod l;
end;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  read(n,m,k,x);
  l:=0;a[l]:=x;
  repeat
    inc(l);a[l]:=(a[l-1]+m) mod n;
  until a[l]=x;
  s:=10 mod l;mi(k);
  write(a[s]);
  close(input);close(output);
end.