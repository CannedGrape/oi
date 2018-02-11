program ex;
var n,h,total:longint;
a,b:array[1..100001] of integer;

procedure start;
var i:longint;
begin
    assign(input,'block.in');
    assign(output,'block.out');
    reset(input);
    rewrite(output);
    readln(n);
    for i:=1 to n do read(b[i]);
    b[n+1]:=0;
    fillchar(a,sizeof(a),0);
    a[n+1]:=maxint;
    h:=0;
    total:=0;
end;

function max(a,b:longint):longint;
begin
    if a>b then exit(a) else exit(b);
end;

procedure work;
var i,j,k:longint;
begin
    j:=0;
    for i:=1 to n do  h:=max(h,b[i]);
    for i:=1 to h do
    begin
        k:=1;
        repeat
            repeat
                if a[k]<b[k] then
                begin
                    inc(a[k]);
                    inc(k);
                    inc(j);
                end;
            until a[k]>=b[k];
            if j>0 then inc(total);
            j:=0;
            inc(k)
        until k>=n+1;
    end;
    write(total);
end;

begin
    start;
    work;
    close(input);
    close(output);
end.