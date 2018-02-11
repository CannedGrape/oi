var a:array[1..100000]of int64;
    s,x:string; ch:char;
    i,j,k,l,n,m:longint;
begin
   assign(input,'expr.in');reset(input);
   assign(output,'expr.out');rewrite(output);
  i:=1;
  while not eof do
   begin
    read(ch);
    if (ch<>'+')and(ch<>'*')and(ord(ch)-48>-1)and(ord(ch)-48<10) then a[i]:=a[i]*10+ord(ch)-48
    else
     begin
      s[i]:=ch;
      inc(i);
     end;
   end;
  k:=i;
  for i:=1 to k do
   begin
    if s[i]='*' then
     begin
      a[i+1]:=a[i+1]*a[i];
      a[i]:=0;
     end;
   end;
  for i:=2 to k do
   a[i]:=a[i]+a[i-1];
   if a[k] div 1000>0 then writeln(a[k] mod 10000)
   else writeln(a[k]);
   close(input);close(output);
end.
