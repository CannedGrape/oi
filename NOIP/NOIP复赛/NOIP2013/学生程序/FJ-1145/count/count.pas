var
i,j,l,n,x:longint;
s,x1:string;
begin
 assign(input,'count.in');
 assign(output,'count.out');
 reset(input);
 rewrite(output);
 read(n,x);
 str(x,x1);
 for i:=1 to n do
 begin
 str(i,s);for j:=1 to length(s) do if s[j]=x1 then inc(l);
 end;
 write(l);
 close(input);
 close(output);
end.