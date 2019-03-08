var n, m , k, x, i, j, h : longint;
function maxab(a, b : longint) : longint;
var r, t : longint;
begin
    repeat
        if a < b then
        begin
            t := a;
            a := b;
            b := t;
        end;
        r := a mod b;
        a := b;
        b := r;
    until  r = 0;
    exit(a);
end;

begin
    assign(input,'circle.in'); reset(input);
    assign(output,'circle.out'); rewrite(output);
    readln(n, m, k, x);
    h := 1;
    for i := 1 to k  do h := h * 10;
    j := m * n div maxab(m, n);
    j := j div m;
    h := h mod j;
    i := 0;
    while i < h do
    begin
        inc(i);
        x := x + m;
        if x > (n - 1) then x := x - n;
    end;
    writeln(x);
    close(input); close(output);
end.


