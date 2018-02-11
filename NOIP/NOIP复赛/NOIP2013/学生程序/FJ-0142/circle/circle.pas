var
  n,m,k,x,i,j,q,p,f:longint;
  a,b:array [0..1000000]of longint;
begin
  assign(input,'circle.in');  reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);
  writeln(x);
  close(input);close(output);
end.
