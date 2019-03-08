var a:array[1..1000]of longint;
    i,j,k,l,n,m:longint;
    s:ansistring;
begin
   assign(input,'level.in');reset(input);
   assign(output,'level.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do readln(s);
  writeln(m);
   close(input);close(output);
end.
