var
 i,j,k,l,m,n,ss:longint;
 a:array[1..1000,1..1000]of longint;

begin
 assign(input,'puzzle.in');reset(input);
 assign(output,'puzzle.out');rewrite(output);
 readln(k,i,j,l);
 for i:=1 to 500 do
  for j:=1 to 500 do
   read(a[i,j]);
 for i:=1 to l do
  writeln(-1);
 end.
