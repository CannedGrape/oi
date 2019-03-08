
program p1999_1(input,output); {Cantor±í}
var n:longint;k:integer;

begin
       assign(input,'cantor.in');
       reset(input);
       readln(n);
       close(input);
       assign(output,'cantor.out');
       rewrite(output);
       k:=trunc(sqrt(n*2))+1;
       while (k*k+k)>=(2*n) do k:=k-1;
       n:=n-(k+1)*k div 2;
       if  (k+1) mod 2=0 then writeln(n,'/',(k+2-n))
           else writeln((k+2-n),'/',n);
       close(output);
end.