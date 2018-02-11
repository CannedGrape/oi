var i,j,n,m,tot:longint;
begin
 assign(input,'count.in'); reset(input);
 assign(output,'count.out'); rewrite(output);
 readln(n,m);  tot:=0;
 for i:=1 to n do
  begin
   j:=i;
   while j>0 do
    begin
     if (j mod 10)=m then inc(tot);
     j:=j div 10;
    end;
  end;
 writeln(tot);
 close(input);  close(output);
end.
