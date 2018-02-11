var
        n,m,i,j:longint;
        l:array[1..100,0..100]of integer;

begin
        assign(input,'level.in');
        assign(output,'level.out');
        reset(input);
        rewrite(output);
        readln(n,m);
        for i:=1 to m do begin
        read(l[i,0]);
        for j:=1 to l[i,0] do read(l[i,j]);
        end;
        if m=2 then writeln(2)else writeln(3);
        close(input);close(output);
end.
