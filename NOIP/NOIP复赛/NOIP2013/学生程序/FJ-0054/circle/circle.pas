var
   n,m,k,x,a,b:int64;
begin
   assign(input,'circle.in');reset(input);
   assign(output,'circle.out');rewrite(output);
   readln(n,m,k,x);
   a:=10;b:=1;
   while k>0 do
     begin
        if k mod 2=1 then b:=(b*a) mod n;
        a:=(a*a) mod n;
        k:=k div 2;
     end;
   b:=b*m mod n;
   writeln((x+b) mod n);
   close(input);close(output);
end.