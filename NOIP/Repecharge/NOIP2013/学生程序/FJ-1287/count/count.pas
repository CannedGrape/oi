var
        n,x,a,i,j,k,l,t,m:longint;
        c:array[1..7] of integer;
        b:string;
begin
        assign(input,'count.in');
        reset(input);
        assign(output,'count.out');
        rewrite(output);
        read(n,x);
        for i:=1 to n do
        begin
                t:=1;
                m:=i;
                str(i,b);
                for j:=1 to length(b)-1 do
                        t:=t*10;
                        for k:=1 to length(b) do
                        begin
                                c[k]:=m div t;
                                m:=m-c[k]*t;
                                t:=t div 10;
                        end;
                        for l:=1 to length(b) do
                                if c[l]=x then inc(a);

        end;
        writeln(a);
        close(input);
        close(output);
end.
