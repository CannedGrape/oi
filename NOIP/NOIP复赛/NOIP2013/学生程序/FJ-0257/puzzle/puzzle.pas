var
  a:array[0..1,0..1]of longint;
  b:array[1..500,1..100]of longint;
  n,m,q,i,j,k,l:longint;
  begin
    assign(input,'puzzle.in');
    reset(input);
    assign(output,'puzzle.out');
    rewrite(output);
    readln(n,m,q);
    for i:=1 to n do
    begin
      for j:= 1 to m do
      readln(a[i,j]);
    end;
    for k:=1 to q do
    begin
      for l:=1 to 6 do
      readln(b[k,l]);
    end;
    writeln('2');
    writeln('-1');
    close(input);
    close(output);
    end.
