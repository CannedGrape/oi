program circle;
var n, m, k, x, lens, lenss : LongInt;
    a, b : array [ 0 .. 1000001 ] of LongInt;
    s : array [ 0 .. 25000001 ] of LongInt;
    ss : array [ 0 .. 10 ] of LongInt;
    t, i, j : LongInt;

procedure sub;
var i, minlen : Longint;
begin
    if (lens < lenss) then
        minlen := lens
    else
        minlen := lenss;
    for i := 0 to minlen do
    begin
        s[i] := s[i] - ss[i];
        if (s[i] < 0) then
        begin
            s[i] := s[i] + 10000;
            Dec(s[i + 1]);
        end;
    end;
    i := minlen + 1;
    while (s[i] < 0) do
    begin
        s[i] := s[i] + 10000;
        Dec(s[i + 1]);
    end;
    for i := lens downto 0 do
        if (s[i] <> 0) then
        begin
            lens := i;
            exit;
        end;
end;

function lessthan : Boolean;
var i : LongInt;
begin
    if (lens < lenss) then
        exit(true)
    else
        if (lens > lenss) then
            exit(false);

    for i := lens downto 0 do
        if (s[i] < ss[i]) then
            exit(true);
    exit(false);
end;

begin
    Assign(Input, 'circle.in');
    Reset(Input);
    Assign(Output, 'circle.out');
    Rewrite(Output);
    ReadLn(n, m, k, x);
    for i := 0 to n - 1 do
        a[i] := i;

    FillChar(s, sizeof(s), 0);
    lens := round(k/4);
    s[lens] := 1;
    for i := 1 to (k mod 4) do
        s[lens] := s[lens] * 10;
    lenss := -1;
    t := n;
    while (t <> 0) do
    begin
        Inc(lenss);
        ss[lenss] := t mod 10000;
        t := t div 10000;
    end;
    while (not (lessthan)) do
        sub;

    if (lens = 0) then
        t := s[lens]
    else begin
        t := s[lens] * 10000;
        Inc(t, s[0]);
    end;

    if (t = 0) then
        t := n;
    if (t = 0) then
        t := n;
    for i := 1 to t do
    begin
        for j := 0 to n-m-1 do
            b[m+j] := a[j];
        for j := n-m to n-1 do
            b[j-n+m] := a[j];
        a := b;
    end;
    WriteLn(a[x]);
    Close(Input);
    Close(Output);
end.
