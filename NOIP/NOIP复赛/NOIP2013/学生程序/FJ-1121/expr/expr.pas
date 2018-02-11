program expr;
var
  a:ansistring;
  d:array[1..200000,1..2] of longint;
  c:array[1..200000] of int64;
  e:array[1..200000] of boolean;
  i,j,k,m,n,s,t:longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(a);
  n:=length(a);
  j:=1;
  for i:=1 to n do
  if (a[i]='+') or (a[i]='*') then
  begin
    k:=k+1;
    val(copy(a,j,i-j),c[k]);
    c[k]:=c[k] mod 10000;
    j:=i+1;
    if a[i]='*' then
    begin
      m:=m+1;
      d[m,1]:=k;
      d[m,2]:=k+1;
    end;
  end;
  k:=k+1;
  val(copy(a,j,n-j+1),c[k]);
  c[k]:=c[k] mod 10000;
  for i:=1 to m do
  begin
    c[d[i,2]]:=c[d[i,1]]*c[d[i,2]] mod 10000;
    e[d[i,1]]:=true;
  end;
  for i:=1 to k do
    if e[i]=false then s:=(s+c[i]) mod 10000;
  writeln(s);
  close(input);
  close(output);
end.
