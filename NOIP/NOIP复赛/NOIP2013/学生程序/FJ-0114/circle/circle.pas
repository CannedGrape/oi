program circle(input,output);
var
i,j,n,m,k,x,ys,bs:longint;
s:int64;

function gys(a,b:longint):longint;
begin
  if b=0 then gys:=a
    else gys:=gys(b,a mod b);
end;

begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  read(n,m,k,x);
  if k<7 then for i:=1 to k do s:=s*10;
  else begin
  s:=1;
  ys:=gys(k,n);
  bs:=k*n div ys;
  k:=k mod bs;
  for i:=1 to k do
    s:=s*10;
  ys:=gys(s,n);
  bs:=s*n div ys;
  end;
  s:=s mod bs;
  s:=s*m;
  x:=x+s;
  x:=x mod n;
  writeln(x);
  close(input);
  close(output);
end.
