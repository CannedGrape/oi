program expr;
var
 ch:char;
 n,x,a:longint;
 begin
                   assign(input,'expr.in');
                   reset(input);
                   assign(output,'expr.out');
                   rewrite(output);

  read(n,ch,x);
  case ch of
  '+':=n+x
  '*':=n*x
  a:=n c x;
  write(a);
                         close(input);
                          close(output);
  end.
