var n,m,k,x,t:int64;
    i,j:longint;
    a,b:array[0..100]of int64;
    xx:boolean;
begin
  assign(input,'circle.in');
  assign(output,'circle.out');
   reset(input);
   rewrite(output);
  readln(n,m,k,x);
  xx:=false;
  if x=n then x:=0;
   t:=1;j:=0;
  while t<n do
   begin
    t:=t*10;
    inc(j);
    a[j]:=t;
   end;
  for i:=1 to j do
   begin
    if (k>=j)and(a[i]mod n=0)then xx:=true;
    b[i]:=x+(m*a[i] mod n);
   end;
  if xx then writeln(b[j]) else
  if k mod j=0 then writeln(b[j]) else
  writeln(b[k mod j]);
  close(input);
  close(output);
end.
