var s:ansistring;
    i,j,n,tot,lena,q:longint;
    s1:char;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
 readln(n,q);tot:=0;
 s1:=chr(q+ord('0'));
 for i:=1 to n do
  begin
   str(i,s);
   lena:=length(s);
   for j:=1 to lena do
    if s[j]=s1 then inc(tot);
  end;
  writeln(tot);
close(input);close(output);
end.
