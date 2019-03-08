var
  i,j:longint;
  n,m,k,x:int64;
  f:array[0..1000000]of int64;

function c(p:int64):int64;
begin
  if p<=1000000 then begin
    if f[p]>=0 then exit(f[p]);
    f[p]:=(c(p div 2)*c(p-p div 2)) mod n;
    exit(f[p]);
  end else exit((c(p div 2)*c(p-p div 2)) mod n);
end;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  fillchar(f,sizeof(f),255);
  readln(n,m,k,x);
  f[0]:=1;
  f[1]:=10 mod n;
  k:=c(k);
  for i:=1 to k do x:=(x+m) mod n;
  writeln(x);
  close(input);
  close(output);
end.

