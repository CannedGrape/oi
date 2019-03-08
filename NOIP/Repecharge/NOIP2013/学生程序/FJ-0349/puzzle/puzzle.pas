program puzzle;
var b,a:array[0..31,0..31] of byte;
    i,j,x,y,s,t,ex,ey,n,m,q:integer;
    ans,min:longint;
procedure open;
begin
    assign(input,'puzzle.in');
    assign(output,'puzzle.out');
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
    readln(n,m,q);
    for i:=1 to n do
    begin
        for j:=1 to m do read(a[i,j]);
        readln;
    end;
end;
procedure dfs(ex,ey:integer);
var i,j,m:integer;
begin
    if b[s,t]=2 then
    begin
        if min>ans then
                min:=ans;
        exit;
    end;
    if a[ex-1,ey]>=1 then
    begin
        inc(ans);
        b[ex-1,ey]:=b[ex,ey];
        b[ex,ey]:=3;
        dfs(ex-1,ey);
        dec(ans);
    end;
    if a[ex+1,ey]>=1 then
    begin
        inc(ans);
        b[ex+1,ey]:=b[ex,ey];
        b[ex,ey]:=3;
        dfs(ex+1,ey);
        dec(ans);
    end;
    if a[ex,ey-1]>=1 then
    begin
        inc(ans);
        b[ex,ey-1]:=b[ex,ey-1];
        b[ex,ey]:=6;
        dfs(ex,ey-1);
        dec(ans);
    end;
    if a[ex,ey+1]>=1 then
    begin
        inc(ans);
        b[ex,ey+1]:=b[ex,ey];
        b[ex,ey]:=3;
        dfs(ex,ey+1);
        dec(ans);
    end;
end;
begin
    open;
    write(-1);
    closed;
end.
