var a:array[1..1000,1..1000] of longint;
    x,m,n,i,j:longint;
begin
    assign(input,'level.in'); reset(input);
    assign(output,'level.out'); rewrite(output);
    readln(n,m);
    read(x);
    for i:=1 to m do
        for j:=1 to x do read(a[i,j]);
   writeln(m);
   close(input);
   close(output);
end.
