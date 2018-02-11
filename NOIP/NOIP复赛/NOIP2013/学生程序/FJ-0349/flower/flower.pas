program flower;
var a:array[0..100010] of longint;
    ans,n,i:longint;
    q:boolean;
procedure open;
begin
    assign(input,'flower.in');
    assign(output,'flower.out');
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
    for i:=1 to n do read(a[i]);
end;
procedure try(q:boolean;x,y:longint);
var i,j,w,k:longint;
begin
    if q then
    begin
        w:=0;
        for i:=x to y do
            if a[i]>w then begin w:=a[i]; k:=i; end;
        if (k+1<=n) and (k-1>=1) and (w>a[k+1]) and (w>a[k-1]) then inc(ans);
        if (k+1>n) and (w>a[k-1]) then inc(ans);
        if (k-1<1) and (w>a[k+1]) then inc(ans);
        q:=false;
        if x<=k-1 then try(q,x,k-1);
        if k+1<=y then try(q,k+1,y);
    end
    else
    begin
        w:=maxlongint;
        for i:=x to y do
            if a[i]<w then begin w:=a[i]; k:=i; end;
        if (k+1<=n) and (k-1>=1) and (w<a[k+1]) and (w<a[k-1]) then inc(ans);
        if (k+1>n) and (w<a[k-1]) then inc(ans);
        if (k-1<1) and (w<a[k-1]) then inc(ans);
        q:=true;
        if x<=k-1 then try(q,x,k-1);
        if k+1<=y then try(q,k+1,y);
    end;
end;
begin
    open;
    init;
    if n=1 then begin write(1); exit; end;
    q:=true;
    try(q,1,n);
    write(ans);
    closed;
end.
