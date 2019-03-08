var i, j, k, q, n, m, x, y, z : longint;
    map : array[1..10000, 1..10000] of longint;
function minab(a, b : longint) : longint;
begin
    if a < b then  exit(a) else exit(b);
end;

function ne(a, b, c : longint) : boolean;
begin
    ne := true;
    if (a = b) or (b = c) or (a = c) then ne := false;
end;

begin
    assign(input,'truck.in'); reset(input);
    assign(output,'truck.out'); rewrite(output);
    readln(n, m);
    for i := 1 to n do
        for j := 1 to n do map[i, j] := -1;
    for i := 1 to m do
    begin
        readln(x, y, z);
        if z > map[x, y] then
        begin
            map[x, y] := z;
            map[y, x] := z;
        end;
    end;
    for k := 1 to n do
        for i := 1 to n do
            for j := 1 to n do
            if ne(k, i, j) and (minab(map[i, k], map[k, j]) >map [i, j]) then
            begin
               map[i, j] := minab(map[i, k], map[k, j]);
               map[j, i] := map[i, j];
            end;
    readln(q);
    for i := 1 to q  do
    begin
        readln(x, y);
        writeln(map[x, y]);
    end;
    close(input);
    close(output);
end.

