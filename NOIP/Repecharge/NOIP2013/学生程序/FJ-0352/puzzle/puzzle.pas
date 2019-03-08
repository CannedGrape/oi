program ex3;
var n,m,q,i:integer;
begin
    assign(input,'puzzle.in');
    assign(output,'puzzle.out');
    reset(input);
    rewrite(output);
    readln(n,m,q);
    if q=1 then write(-1)
    else
    begin
        for i:=1 to q-1 do writeln(-1);
        write(-1);
    end;
    close(input);
    close(output);
end.
