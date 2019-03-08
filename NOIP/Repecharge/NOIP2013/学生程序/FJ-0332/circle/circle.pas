var n,m,k,x,i,j:longint;

begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);
  for i:=1 to k do
    for j:=1 to 10 do
        x:=(x+m)mod n;
  writeln(x);
  close(input); close(output);
end.

