program kjl;
var n,x,i,j,k:integer;
    a:array[1..1000000]of integer;
    f1,f2:text;
    begin
    assign(f1,'count.in');
    assign(f2,'count.out');
    reset(f1);
    rewrite(f2);
    read(f1,n,x);
    for i:=1 to n do
    for x:=0 to 9 do
    j:=a[x];
    write(f2,j);
     close(f1);
     close(f2);
     end.
