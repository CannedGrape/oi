var n,m,k,x,s,s1,i:longint;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);

  readln(n,m,k,x);
  s:=m mod n;
  if k<=10000000 then
    for i:=1 to k do s:=(s*10) mod n
  else for i:=1 to k-m div 10 do s:=(s*10) mod n;
  s1:=x mod n;
  writeln((s+s1) mod n);

  close(input);
  close(output);
end.
