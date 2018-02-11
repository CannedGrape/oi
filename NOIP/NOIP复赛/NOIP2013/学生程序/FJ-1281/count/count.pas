var  n,x,i,j,len,tot:longint;
     s1,s:string;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
read(n,x);
str(x,s1);
for i:=x to n do
        begin
                str(i,s);
                len:=length(s);
                for j:=1 to len do if s[j]=s1 then inc(tot);
        end;
writeln(tot);
close(input);close(output);
end.
