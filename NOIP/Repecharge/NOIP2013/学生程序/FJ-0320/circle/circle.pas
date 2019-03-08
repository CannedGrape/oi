var n,m,k,x,i,j,first,l,step,std,ans,final:longint;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);
  first:=x;
  inc(x,m);
  x:=x mod n;
  step:=1;
  while (x<>first) and (step<n) do
  begin
    inc(x,m);
    x:=x mod n;
    inc(step);
  end;
  std:=10 mod step;
  ans:=std;
  for i:=1 to k do ans:=ans*std mod step;
  final:=x;
  for i:=1 to ans do
  begin
    final:=final+m;
    final:=final mod n;
  end;
  writeln(final);
  close(input); close(output);
end.
