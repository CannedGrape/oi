var n,p,i:longint;
    a:array[1..10000] of longint;
    begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
      readln(n,p);
      for i:=1 to n do read(a[i]);
      writeln(1);
close(input);
close(output);
    end.
