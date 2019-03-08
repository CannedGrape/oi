program flower;

const
maxn=100000;

var
i,n:0..maxn+1;
a1,a2:0..maxn+1;
a:array[0..maxn+1] of longint;

begin
assign(input,'flower.in');
reset(input);
readln(n);
for i:=1 to n do read(a[i]);
for i:=1 to n do begin
  if (a[i]<a[i+1]) and (a[i]<a[i-1]) then a1:=a1+1;
  if (a[i]>a[i+1]) and (a[i]>a[i-1]) then a2:=a2+1;
  end;
  assign(output,'flower.out');
  rewrite(output);
if a1>a2 then writeln(a1*2-1) else writeln(a2*2-1);
close(input);
close(output);
end.
