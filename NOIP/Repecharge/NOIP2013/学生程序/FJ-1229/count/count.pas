var n,x,i,ans:longint;
    a,b,xx:ansistring;

begin

        assign(input,'count.in');
        reset(input);
        assign(output,'count.out');
        rewrite(output);

        readln(n,x);
        ans:=0;
        str(x,xx);
        for i:=1 to n do
        begin
                str(i,b);
                a:=a+b;
        end;
        for i:=1 to length(a) do
        if a[i]=xx then inc(ans);
        writeln(ans);

        close(input);
        close(output);

end.