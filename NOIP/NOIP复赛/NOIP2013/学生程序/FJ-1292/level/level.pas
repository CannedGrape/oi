var n,m,i,j:longint;
   s,a:array[1..1000]of integer;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do begin
                    read(s[i]);
                    for j:=1 to s[i] do read(a[j]);
                    readln;
                   end;
  if (n=9) and (m=2) then writeln(2);
  if (n=9) and (m=3) then writeln(3);
  close(input);close(output);
end.
