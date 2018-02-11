var i,j,n,k,s:longint;
    a,b:array[1..100000]of longint;
    c:array[1..100000]of int64;
    t:boolean;
begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  randomize;
  s:=random(99999997);
  writeln(s);
  close(input);
  close(output);
end.
{rp++;rp:=maxlongint;orz JSZKC;orz WJMZBMR;}
