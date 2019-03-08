program fuck;
var
 i,j,k,l,s,t,m,n,he,ta:longint;
 a:array[0..1000000] of longint;
begin
 assign(input,'block.in');
 assign(output,'block.out');
 reset(input);
 rewrite(output);
 readln(n);
 s:=0;
 he:=0;
 ta:=0;
 for i:=1 to n do
  begin
  read(m);
  l:=0;
  while (ta<>0) and (a[ta]>m) do begin dec(ta); if l<a[ta+1] then l:=a[ta+1]; end;
  if l<>0 then s:=s+l-m;
  inc(ta);
  a[ta]:=m;
  end;
 s:=s+a[ta];
 readln;
 writeln(s);
 close(input);
 close(output);
end.
