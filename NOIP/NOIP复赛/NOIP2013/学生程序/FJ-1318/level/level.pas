program kjk;
var l,m,n,i,j,k:integer;
    a:array[1..1000]of integer;
    f1,f2:text;
    begin
    assign(f1,'level.in');
    assign(f2,'level.out');
    reset(f1);
    rewrite(f2);
    close(f1);
    close(f2);
    end.