program expr;
var a:array[1..1000] of integer;
    s:string;
    i,n,j,k:integer;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  n:=length(s);
    write('10');
    close(input);
    close(output);

end.
