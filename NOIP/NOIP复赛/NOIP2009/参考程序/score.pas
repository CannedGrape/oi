type
    arr = array[1..2] of longint;
var
    i, j, n, m: longint;
    a: array[1..5001] of arr;

procedure swap(var a, b: arr);
var
    c: arr;
begin
    c := a;
    a := b;
    b := c;
end;

procedure qsort(l, r: longint);
var
    i, j, temp1, temp2: longint;
begin
    i := l;
    j := r;
    temp1 := random(r - l + 1) + l;
    temp2 := a[temp1, 2];
    temp1 := a[temp1, 1];
    repeat
        while (a[i, 1] > temp1) or ((a[i, 1] = temp1) and (a[i, 2] < temp2)) do
            inc(i);
        while (a[j, 1] < temp1) or ((a[j, 1] = temp1) and (a[j, 2] > temp2)) do
            dec(j);
        if i <= j then
        begin
            swap(a[i],a[j]);
            inc(i);
            dec(j);
        end;
    until i>j;
    if i < r then qsort(i, r);
    if j > l then qsort(l, j);
end;

begin
    randomize;
    assign(input, 'score.in'); reset(input);
    assign(output, 'score.out'); rewrite(output);
    readln(n, m);
    m := trunc(m * 1.5);
    for i := 1 to n do
        readln(a[i, 2], a[i, 1]);
    a[n + 1, 1] := 0;
    qsort(1, n);
    i := m;
    while a[i + 1, 1] = a[i, 1] do
        inc(i);
    writeln(a[i, 1], ' ', i);
    for j := 1 to i do
        writeln(a[j, 2], ' ', a[j, 1]);
    close(input);
    close(output);
end.
