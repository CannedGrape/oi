type arr = array[1..30000, 1..2] of longint;
var ans, g, i, k, n, m1, m2, total: longint;
    a: arr;

procedure factorization(k: longint; var a: arr; var link: longint);
var i: longint;
begin
    i := 1;
    link := 0;
    repeat
        inc(i);
        if k mod i = 0 then
        begin
            inc(link);
            a[link, 1] := i;
            a[link, 2] := 0;
            while k mod i = 0 do
            begin
                inc(a[link, 2]);
                k := k div i;
            end;
        end;
    until k = 1;
end;

procedure main;
var i, z, max: longint;
begin
    max := -1;
    read(k);
    for i := 1 to total do
    begin
        if k mod a[i, 1] <> 0 then exit;  {exit means return in C?}
        z := 0;
        while k mod a[i, 1] = 0 do
        begin
            inc(z);
            k := k div a[i, 1];
        end;
        if (a[i, 2] + z - 1) div z > max then
            max := (a[i, 2] + z - 1) div z;
    end;
    if max < ans then ans := max;
end;

begin
    assign(input, 'cell.in'); reset(input);
    assign(output, 'cell.out'); rewrite(output);
    ans := maxlongint;
    readln(n);
    readln(m1, m2);
    if m1 = 1 then
    begin
        writeln(0); close(input); close(output); halt;
    end;
    factorization(m1, a, total);
    for i := 1 to total do
        a[i, 2] := a[i, 2] * m2;
    for i := 1 to n do
        main;
    if ans = maxlongint then
        writeln(-1)
    else
        writeln(ans);
    close(input);
    close(output);
end.
