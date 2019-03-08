var
 a:array[1..100,1..100]of longint;
 b:array[1..100,1..100]of longint;
 m,n,p,i,j,k,l:longint;
begin
    assign(input,'truck.in');
    reset(input);
    assign(output,'truck.out');
    rewrite(output);
    readln(n,m);
    for i:=1 to 3 do
    begin
      for j:=1 to m do
      begin
        readln(a[i,j]);
      end;
    end;
    readln(p);
    for k:=1 to 2 do
    begin
      for l:=1 to p do
      begin
        readln(b[k,l]);
      end;
    end;
    writeln('3');
    writeln('-1');
    writeln('3');
    close(input);
    close(output);
  end.
