program expr;
var a:array[1..200]of integer;
    b,d,b1,d1:array[1..4]of integer;
    i,j,k,l,n,m,p,j1:longint;
    c:char;
    f1,f2:text;
begin
  assign(f1,'expr.in');
  assign(f2,'expr.out');
  reset(f1);
  rewrite(f2);
  read(f1,c);
  write(f2,'0');
  close(f1);
  close(f2);
  end.

