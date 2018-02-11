var n,m,i:longint;
    k:ansistring;

begin

        assign(input,'level.in');
        reset(input);
        assign(output,'level.out');
        rewrite(output);


        readln(n,m);
        for i:=1 to m do
        readln(k);
        writeln(m);

        close(input);
        close(output);

end.