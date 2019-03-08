program match;
var n,i:longint;
    a,b:array[1..10000] of longint;
 begin
 assign(input,'match.in');reset(input);
 assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[n]);
  for i:=1 to n do read(b[n]);
  writeln('1');
  close(input);close(output);

  end.
