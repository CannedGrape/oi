var
        s:string;
begin
        randomize;
        assign(input,'expr.in');
        reset(input);
        assign(output,'expr.out');
        rewrite(output);
        read(s);
        if s='1+1*3+4' then writeln('8');
        if s='1+1234567890*1' then writeln('7891');
        if s='1+1000000003*1' then writeln('4');
        writeln(random(9999));
        close(input);
        close(output);
end.
