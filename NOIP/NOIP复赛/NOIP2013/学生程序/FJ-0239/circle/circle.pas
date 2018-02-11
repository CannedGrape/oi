var t,i,j,m,n,k,x:longint;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  readln(n,m,k,x);
  t:=(m*10) mod n;
  for i:=1 to k do
    t:=(t*10) mod n;
  if k>0 then writeln((t+x) mod n) else writeln((x+m) mod n);
  close(input);
  close(output);
end.
{rp++;rp:=maxlongint;orz JSZKC;orz WJMZBMR;}
