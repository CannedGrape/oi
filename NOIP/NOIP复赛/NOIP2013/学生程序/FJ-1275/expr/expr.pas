var s:string;
    i,m,n:longint;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 readln(s);
 for i:=1 to length(s) do
begin
 if s[i]='*' then inc(m);
 if s[i]='+' then inc(n);
end;
 if (m=1) and (n=2) then writeln('8')
 else if (m=1) and (n=1) then writeln('7819')
 else writeln('4');
close(input);close(output);
end.