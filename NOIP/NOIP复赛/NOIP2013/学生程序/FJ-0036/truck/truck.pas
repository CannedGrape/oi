program truck;
var f : array [ 1 .. 10001, 1 .. 10001 ] of LongInt;
    n, m, x, y, z, q : LongInt;
    i, j, k : LongInt;

function min(x, y : LongInt) : LongInt;
begin
    if (x > y) then
        exit(y)
    else
        exit(x);
end;

begin
    Assign(Input, 'truck.in');
    Reset(Input);
    Assign(Output, 'truck.out');
    Rewrite(Output);
    FillChar(f, sizeof(f), 0);
    ReadLn(n, m);
    for i := 1 to m do
    begin
        ReadLn(x, y, z);
        f[x, y] := z;
        f[y, x] := z;
    end;
    for k := 1 to n do
        for i := 1 to n do
            for j := 1 to n do
            begin
                if (i = j) then
                    continue;
                if ((f[i, k] > 0) and (f[k, j] > 0)) and ((f[i, j] = 0) or ((f[i, j] < f[i, k]) and (f[i, j] < f[k, j]))) then
                    f[i, j] := min(f[i, k], f[k, j]);
            end;
    ReadLn(q);
    for i := 1 to q do
    begin
        ReadLn(x, y);
        if (f[x, y] <> 0) then
            WriteLn(f[x, y])
        else
            WriteLn(-1);
    end;
    Close(Input);
    Close(Output);
end.
