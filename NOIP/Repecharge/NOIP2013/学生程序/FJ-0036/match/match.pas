program match;
type arr = array [ 1 .. 100001 ] of LongInt;
var n, i, ans, minlen, len : LongInt;
    a, b, ta, tb : arr;

procedure search(x : LongInt; t : LongInt);
var i, z : LongInt;
begin
    len := 0;
    if (x = n + 1) then
    begin
        for i := 1 to n do
        begin
            len := len + (a[i] - b[i]) * (a[i] - b[i]);
            if (len > minlen) then
                exit;
        end;
        if (len = minlen) then
            if (ans > t) then
                ans := t;
        exit;
    end;
    search(x + 1, t);
    for i := 1 to n do
    begin
        z := a[i + 1];
        a[i + 1] := a[i];
        a[i] := z;
        search(x + 1, t + 1);
        z := a[i + 1];
        a[i + 1] := a[i];
        a[i] := z;


        z := b[i + 1];
        b[i + 1] := b[i];
        b[i] := z;
        search(x + 1, t + 1);
        z := b[i + 1];
        b[i + 1] := b[i];
        b[i] := z;


        z := a[i + 1];
        a[i + 1] := a[i];
        a[i] := z;
        z := b[i + 1];
        b[i + 1] := b[i];
        b[i] := z;
        search(x + 1, t + 2);
        z := a[i + 1];
        a[i + 1] := a[i];
        a[i] := z;
        z := b[i + 1];
        b[i + 1] := b[i];
        b[i] := z;
    end;
end;

procedure qsort(var a : arr);
    procedure sort(l, r : LongInt);
    var i, j, mid, t : LongInt;
    begin
        i := l;
        j := r;
        mid := a[(l + r) div 2];
        repeat
            while (a[i] < mid) do
                Inc(i);
            while (a[j] > mid) do
                Dec(j);
            if (i <= j) then
            begin
                t := a[i];
                a[i] := a[j];
                a[j] := t;
                Inc(i);
                Dec(j);
            end;
        until (i > j);
        if (i < r) then
            sort(i, r);
        if (l < j) then
            sort (l, j);
    end;
begin
    sort(1, n);
end;

begin
    Assign(Input, 'match.in');
    Reset(Input);
    Assign(Output, 'match.out');
    Rewrite(Output);
    ReadLn(n);
    for i := 1 to n do
    begin
        read(a[i]);
        ta[i] := a[i];
    end;
    ReadLn;
    for i := 1 to n do
    begin
        read(b[i]);
        tb[i] := b[i];
    end;
    ReadLn;
    qsort(ta);
    qsort(tb);
    minlen := 0;
    for i := 1 to n do
        minlen := minlen + (ta[i] - tb[i]) * (ta[i] - tb[i]);
    ans := MAXLONGINT;
    search(1, 0);
    WriteLn(ans);
    Close(Input);
    Close(Output);
end.
