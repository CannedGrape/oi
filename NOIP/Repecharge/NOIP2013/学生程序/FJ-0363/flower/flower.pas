var i, j, m, n,  k max : longint;
    h : array[1..1000] of integer;
    a : array[1..1000] of integer;
function ok(p : integer) : boolean;
var l : integer;
begin
    ok := true;
    if (p < 3) then exit(true);
    for l := 2 to m - 1 do
        if (a[l] > a[l - 1]) and (a[l + 1] > a[l]) then ok := false;
    for l := 2 to m - 1 do
        if (a[l] < a[l - 1]) and (a[l + 1] < a[l]) then ok := false;
end;

procedure dfs(step : integer);
var i : integer;
begin
    if step > n then
    begin
        if ok(step) then
         if  max < m then max := m;
    end else
    for i := 1 to 2 do
    begin
        if (i = 1) then
        begin
            inc(m);
            a[m] := h[step];
            dfs(step + 1);
            dec(m);
        end else
        dfs(step + 1);
    end;
end;

begin
    assign(input,'flower.in'); reset(input);
    assign(output,'flower.out'); rewrite(output);
    readln(n);
    k := 0;  m := 0; max := 0;
    for i := 1 to n do read(h[i]);
    dfs(1);
    writeln(max);
    close(input);
    close(output);
end.
