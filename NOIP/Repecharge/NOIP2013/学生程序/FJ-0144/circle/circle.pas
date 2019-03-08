var
  n,q,m,k,x,l,i,p,t:longint;o:int64;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle,out');rewrite(output);
  readln(n,m,k,x);
  o:=1;l:=0;
  repeat
    o:=o*10;
    inc(l);
  until l=k;
  p:=(o*m mod n)+n;
  t:=n-(x+1);
  if (o*m<n) and(x+o*m>n) then writeln(x+o*m-n)
  else
  writeln(p-t-1);
  close(input);close(output);
end.
