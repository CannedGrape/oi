 program cc;
 var
 n,m,k,x,l:longint;
 function gcd(a,b:longint):longint;
 begin
   if b=0 then gcd:=a
   else gcd:=gcd(b,a mod b);
 end;
 function mm(kk:longint):longint;
 var
 t,mt,i:longint;
 begin
   mt:=1;
   if gcd(n,10)=1 then
   begin
     while kk>n-1 do kk:=kk-n+1;
     for i:=1 to kk do
      mt:=mt*10 mod n;
     exit(mt);
   end;
   for i:=1 to kk do
    mt:=mt*10 mod n;
   exit(mt);
 end;
 begin
 assign(input,'circle.in');
 reset(input); 
 assign(output,'circle.out');
 rewrite(output);
   read(n,m,k,x);
   l:=m*mm(k) mod n;
   x:=x+l;
   while x>n-1 do x:=x mod n;
   writeln(x);
 close(input);
 close(output);
 end.
