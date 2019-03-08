program number;
 var n,p,a,b,c,d,e,f,i,j,k,l:integer;
  begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p,a,b,c,d,e);
  e:=a+b+c+d+e;
  d:=a+b+c+d;
  c:=a+b+c;
  b:=a+b;
  f:=a;
  i:=f+b;
  j:=i+c;
  k:=j+d;
  l:=k+e;
  if (l>k) and (l>j) and (l>i) and (l>f) then writeln(l)
                                         else writeln(f);
  close(input);
  close(output);
 end.
