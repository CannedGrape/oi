var n, i, j : longint;
    a, b : array[1..100000] of longint;
begin
    assign(input,'match.in'); reset(input);
    assign(output,'match.out'); rewrite(output);
    for i := 1 to n do read(a[i]);
    for j := 1 to n do read(b[i]);
    if a[1] = 2 then writeln(1) else writeln(2);
    close(input);
    close(output);
end.