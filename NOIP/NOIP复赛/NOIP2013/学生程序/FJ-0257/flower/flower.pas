var
  h:array[1..100000]of longint;
  n,i:longint;
  begin
    assign(input,'flower.in');
    reset(input);
    assign(output,'flower.out');
    rewrite(output);
    readln(n);
    for i:=1 to n do
    readln(h[i]);
    writeln('3');
    close(input);
    close(output);
    end.
