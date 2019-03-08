var i,j,n,tot,x:longint;
    pd:boolean;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
 read(n,x);
 for i:=1 to n do
  begin
   j:=i;pd:=true;
   while pd do
    begin
     if j mod 10=x then inc(tot);
     j:=j div 10;
     if j=0 then pd:=false;
    end;
  end;
 write(tot);
close(input);close(output);
end.
