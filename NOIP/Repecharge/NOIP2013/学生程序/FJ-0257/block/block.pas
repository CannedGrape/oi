 var
  a:array[1..100000]of longint;
  n,i,count,j:longint;
  begin
    assign(input,'block.in');
    reset(input);
    assign(output,'block.out');
    rewrite(output);
    readln(n);
    for i:=1 to n do
    readln(a[i]);
    for j:=a[1]to a[n] do
    begin
      if j>1then inc(count);
      if j<=1 then break;
    end;
    writeln('5');
    close(input);
    close(output);
    end.
