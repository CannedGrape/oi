program ex3;
var n,m,q:longint;
a:array[1..10000,1..10000] of longint;

procedure start;
var i,j,x,y:longint;
begin
    assign(input,'truck.in');
    assign(output,'truck.out');
    reset(input);
    rewrite(output);
    readln(n,m);
    for i:=1 to n do for j:=1 to n do a[i,j]:=-1;
    for i:=1 to m do
    begin
        read(x,y);
        readln(a[x,y]);
        a[y,x]:=a[x,y];
    end;
end;

function max(a,b:longint):longint;
begin
    if a>b then exit(a) else exit(b);
end;

function min(a,b:longint):longint;
begin
    if a>b then exit(b) else exit(a);
end;

procedure find;
var i,j,k,h:longint;
b:boolean;
begin
    for i:=1 to n do
        for j:=1 to n do
        if (i<>j) then
            for k:=1 to n do
            if (i<>k) and (j<>k) then
            begin
                h:=min(a[i,k],a[k,j]);
                a[i,j]:=max(a[i,j],h);
            end;
end;

procedure work;
var i,st,se:longint;
begin
    readln(q);
    for i:=1 to q-1 do
    begin
        readln(st,se);
        writeln(a[st,se]);
    end;
    readln(st,se);
    write(a[st,se]);
end;

begin
    start;
    find;
    work;
    close(input);
    close(output);
end.
