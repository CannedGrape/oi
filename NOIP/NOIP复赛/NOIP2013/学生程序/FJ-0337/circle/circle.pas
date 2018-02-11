program circle;
var k,m,n:integer;
    x,c,i:longint;
    begin
    assign(input,'circle.in');reset(input);
    assign(output,'circle.out');rewrite(output);
    read(n,m,k,x);
    if (x<0) or (x>n) then halt;
    for i:=1 to k do c:=c*10;
    for i:=1 to c do
    begin
    x:=x+m;
    if x>(n-1) then x:=x mod n
    end;
    writeln(x);
    close(input);close(output);
    end.

