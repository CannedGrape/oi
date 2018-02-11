program ex2;
var n,ans1,ans2:longint;
a:array[1..100000] of longint;

procedure start;
var i:longint;
begin
    assign(input,'flower.in');
    assign(output,'flower.out');
    reset(input);
    rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);
end;

procedure work1;
var i,temp,k:longint;
begin
    i:=1;
    temp:=0;
    k:=1;
    repeat
        if (k=1) and (a[i]<temp) then
        begin
            temp:=a[i];
        end;
        if (k=2) and (a[i]>temp) then
        begin
            temp:=a[i];
        end;
        if (k=1) and (a[i]>temp) then
        begin
            temp:=a[i];
            inc(ans1);
            k:=2;
        end;
        if (k=2) and (a[i]<temp) then
        begin
            temp:=a[i];
            inc(ans1);
            k:=1;
        end;
        inc(i);
    until i=n+1;
end;

procedure work2;
var i,temp,k:longint;
begin
    i:=1;
    temp:=maxlongint;
    k:=2;
    repeat
        if (k=2) and (a[i]>temp) then
        begin
            temp:=a[i];
        end;
        if (k=1) and (a[i]<temp) then
        begin
            temp:=a[i];
        end;
        if (k=1) and (a[i]>temp) then
        begin
            temp:=a[i];
            inc(ans2);
            k:=2;
        end;
        if (k=2) and (a[i]<temp) then
        begin
            temp:=a[i];
            inc(ans2);
            k:=1;
        end;
        inc(i);
    until i=n+1;
end;

begin
    start;
    work1;
    work2;
    if ans1>ans2 then write(ans1) else write(ans2);
    close(input);
    close(output);
end.
