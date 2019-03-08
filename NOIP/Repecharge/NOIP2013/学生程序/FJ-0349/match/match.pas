program match;
var a,b,c:array[1..100000] of longint;
    f:array[0..100000] of longint;
    min,n,i,j,m,ans:longint;
    w:boolean;
procedure qsort(x,y:longint);
var i,j,k,m:longint;
begin
    i:=x; j:=y; k:=a[(x+y) div 2];
    repeat
        while a[i]<k do inc(i);
        while a[j]>k do dec(j);
        if i<=j then
        begin
            m:=a[i];a[i]:=a[j];a[j]:=m;
            m:=b[i];b[i]:=b[j];b[j]:=m;
            inc(i); dec(j);
        end;
    until i>j;
    if x<j then qsort(x,j);
    if i<y then qsort(i,y);
end;
procedure qsort2(x,y:longint);
var i,j,k,m:longint;
begin
    i:=x; j:=y; k:=c[(x+y) div 2];
    repeat
        while c[i]<k do inc(i);
        while c[j]>k do dec(j);
        if i<=j then
        begin
            m:=c[i];c[i]:=c[j];c[j]:=m;
            inc(i); dec(j);
        end;
    until i>j;
    if x<j then qsort2(x,j);
    if i<y then qsort2(i,y);
end;
begin
    assign(input,'match.in');
    assign(output,'match.out');
    reset(input);
    rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);
    for i:=1 to n do begin read(c[i]); b[i]:=c[i]; end;
    qsort(1,n);
    qsort2(1,n);
    ans:=0;
    i:=1;
    while i<=n do
    begin
        w:=true;
        if b[i]<>c[i] then
            for j:=1 to n do
                if b[i]=c[j] then
                begin
                    m:=b[i]; b[i]:=b[j]; b[j]:=m;
                    inc(ans);
                    w:=false;
                end;
        if w then inc(i);
    end;
    write(ans);
    close(input);
    close(output);
end.
