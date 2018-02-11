var h : array[1..100000] of integer;
    i, j, n, sum : longint;
    flag : boolean;
begin
    assign(input,'block.in'); reset(input);
    assign(output,'block.out'); rewrite(output);
    sum := 0;
    readln(n);
    for i := 1 to n do
    begin
        read(h[i]);
        sum := sum + h[i];
    end;
    j := 0;
    repeat
        flag := false;
        for i := 1 to n do
            if h[i] > 0 then
            begin
                dec(h[i]);
                dec(sum);
                flag := true;
            end else if ( h[i] = 0) and flag then break;
        if flag then inc(j);
    until sum = 0;
    writeln(j);
    close(input); close(output);
end.

