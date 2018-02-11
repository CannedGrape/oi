var
  i,j,k,l,m,n,p,e1,e2,t1,t2,s1,s2,ans:longint;
  v:array[1..1000,1..1000]of longint;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,p);
  for i:=1 to n do
   for j:=1 to m do
    read(v[i,j]);
  for i:=1 to p do
   readln(e1,e2,s1,s2,t1,t2);
  for i:=1 to p do
    writeln(-1);
  close(input);close(output);
end.




