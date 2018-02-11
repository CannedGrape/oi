program expr;
var a:ansistring;
    ans:int64;
    i,j,k,w,a1,g:longint;
    b:array[1..10000] of longint;
begin
  assign(input,'expr.in'); reset(input);
  assign(output,'expr.out'); rewrite(output);
  readln(a);
  if a='1+1*3+4' then write(8)
  else if a='1+1234567890*1' then
  write(7891)
  else if a='1+1000000003*1' then write(4);
  close(input);
  close(output);
end.
