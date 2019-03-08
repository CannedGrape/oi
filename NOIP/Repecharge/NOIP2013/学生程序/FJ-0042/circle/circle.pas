var n,m,k,x,y,s:longint;
begin
        assign(input,'circle.in');reset(input);
        assign(output,'circle.out');rewrite(output);
        readln(n,m,k,x);
        y:=1;
        s:=10;
        while k>0 do
                begin
                        if k mod 2=1 then y:=(y*s)mod n;
                        s:=(s*s) mod n;
                        k:=k div 2;
                end;
        writeln((y*m+x)mod n);
        close(input);close(output);
end.
