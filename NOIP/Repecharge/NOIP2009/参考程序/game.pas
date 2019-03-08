var
    i, j, k, n, m, p, pastmax, nowmax: longint;
    coin, f, step: array[0..1000, 0..1000] of longint;
    cost, past: array[1..1000] of longint;
begin
    assign(input, 'game.in'); reset(input);
    assign(output, 'game.out'); rewrite(output);
    filldword(step, sizeof(step) shr 2, maxlongint);
    readln(n, m, p);
    for i:=2 to n do
        past[i] := i - 1;
    past[1] := n;
    for i := 1 to n do
        for j := 1 to m do
            read(coin[j, i]);
    for i := 1 to n do 
        read(cost[i]);
    pastmax:=0;
    for i:=1 to m do
    begin
        nowmax := -maxlongint;
        for j := 1 to n do
        begin
            if step[i - 1, past[j]] < p then
            begin
                if pastmax - cost[past[j]] > f[i - 1, past[j]] then
                begin
                    step[i, j] := 1;
                    f[i, j] := pastmax - cost[past[j]] + coin[i, past[j]];
                end
                else 
                begin
                    step[i, j] := step[i - 1, past[j]] + 1;
                    f[i, j] := f[i - 1, past[j]] + coin[i, past[j]];
                end;
            end
            else
            begin
                step[i, j] := 1;
                f[i, j] := pastmax - cost[past[j]] + coin[i, past[j]];
            end;
            if f[i, j] > nowmax then
                nowmax := f[i, j];
        end;
        pastmax := nowmax;
    end;
    writeln(nowmax);
    close(input);
    close(output);
end.
