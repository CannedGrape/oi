var a,ans,temp:ansistring;
    b:array[1..100001] of ansistring;
    i,j,k,k1,k2,k3,k4,t,code,ans2:longint;

begin

        assign(input,'expr.in');
        reset(input);
        assign(output,'expr.out');
        rewrite(output);

        readln(a);
        ans2:=0;
        t:=0;
        k:=1;
        for i:=1 to length(a) do
        begin
                if (a[i]='+') or (a[i]='*') then
                begin
                        inc(t);
                        for j:=k to i-1 do b[t]:=b[t]+a[j];
                        inc(t);
                        b[t]:=a[i];
                        k:=i+1;
                end;
        end;
        inc(t);
        for i:=length(a) downto 1 do
        begin
                if (a[i]<>'+') and (a[i]<>'*') then
                temp:=temp+a[i] else break;
        end;
        for i:=length(temp) downto 1 do
        b[t]:=b[t]+temp[i];
        for i:=1 to t do
        begin
                if b[i]='*' then
                begin
                        val(b[i-1],k1,code);
                        val(b[i+1],k2,code);
                        k3:=k1*k2;
                        str(k3,b[i+1]);
                        b[i]:=' ';
                        b[i-1]:=' ';
                end;
        end;
        for i:=1 to t do
        if (b[i]<>' ') and (b[i]<>'+') then
        begin
                val(b[i],k4,code);
                ans2:=ans2+k4;
        end;
        str(ans2,ans);
        if length(ans)<=4 then writeln(ans);
        if length(ans)>4 then
        begin
                for i:=length(ans)-3 to length(ans) do
                if ans[i]<>'0' then write(ans[i]);
                writeln;
        end;

        close(input);
        close(output);

end.
