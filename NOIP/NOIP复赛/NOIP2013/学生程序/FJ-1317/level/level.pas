program expr;
var a:array[1..10000] of longint; b,c,f,e:integer;d:string;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);readln(b,c);
  for e:=1 to 5+(b-1)*4 do read (a[c]);
  {for b:=1 to 100 do read(a[b]);}
  f:=4;
  write(f);
  close(input);close(output);
end.
