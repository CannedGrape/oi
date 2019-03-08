program block;
var a:array[0..100010] of integer;
    i,j,n,ans:longint;
procedure open;
begin
    assign(input,'block.in');
    assign(output,'block.out');
    reset(input);
    rewrite(output);
end;
procedure closed;
begin
    close(input);
    close(output);
end;
procedure init;
begin
    readln(n);
    fillchar(a,sizeof(a),0);
    for i:=1 to n do read(a[i]);
    ans:=0;
end;
procedure make;
var i,j,k,l,min,x,y:longint;
begin
    y:=1; x:=0;
    while y<=n do
    begin
        while a[y]<a[y+1] do inc(y);
        ans:=ans+a[y]-a[x];
        x:=y+1;
        y:=x;
    end;
    write(ans);
end;
begin
    open;
    init;
    make;
    closed;
end.
