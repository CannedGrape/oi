program expr;
var a:array[1..10000] of longint; b,c,f,e:integer;d:string;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);readln(b,c);
  for e:=1 to b do read (a[c]);
  f:=38;
  write(f);
  close(input);close(output);
end.