var
        n,x,i,ans,j:longint;
        s:string;
begin
        assign(input,'count.in');
        assign(output,'count.out');
        reset(input);
        rewrite(output);
        readln(n,x);
        for i:=1 to n do begin
                str(i,s);
                for j:=1 to length(s) do if s[j]=chr(x+ord('0'))then inc(ans);
        end;
        writeln(ans);
        close(input);close(output);
end.