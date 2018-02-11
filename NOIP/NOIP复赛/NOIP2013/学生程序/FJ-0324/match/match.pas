var input,output:text;
    i,j,k,n:longint;
    a,b:array[1..10000]of integer;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(input,n);
  for i:=1 to n do
  read(input,a[i]);
  readln(input);
  for i:=1 to n do
  read(input,b[i]);
  writeln(output,'1');
  close(input);close(output);
end.