PROGRAM a2(input,output);
var
  s:string;
  a:array[1..100] of integer;
  ans,i:integer;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(s);
  i:=lengh(s);
  writeln;
end.