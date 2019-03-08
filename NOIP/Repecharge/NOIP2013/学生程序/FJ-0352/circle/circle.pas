program ex;
var n,m,k,x,total:longint;
a:array[1..1000000] of boolean;
b:array[1..1000000] of longint;

procedure start;
begin
    assign(input,'circle.in');
    assign(output,'circle.out');
    reset(input);
    rewrite(output);
    readln(n,m,k,x);
    fillchar(a,sizeof(a),false);
    x:=x+1;
    total:=1;
end;

procedure work;
var i:longint;
begin
    a[x]:=true;
    b[1]:=x;
    inc(total);
    repeat
        x:=x+m;
        if x<=n then
            if a[x]=false then
            begin
                a[x]:=true;
                b[total]:=x;
                inc(total);
            end;
        if x>n then
        begin
            x:=x mod n;
            if a[x]=false then
            begin
                a[x]:=true;
                b[total]:=x;
                inc(total);
            end;
        end;
    until a[x]=true;
end;

procedure work2;
var i,j:longint;
begin
    j:=k;
    k:=1;
    for i:=1 to j do
    begin
        k:=k*10;
        if k>total then k:=k mod total;
    end;
    write(b[k]-1);
end;

begin
    start;
    work;
    work2;
end.
