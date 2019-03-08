
var n,m,k,x,i,s1,t,s,p,q,j,a,b,c,tot,t1,tot2:longint;
 begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
   read(n,m,k,x);
   if k<7 then
   t1:=1;
   begin
    for i:=1 to k do t1:=t1*10;
    s1:=m*t1+x;
    tot2:=s1 mod n;
    writeln(output,tot2);
    close(input); close(output); halt;
    end;
   t:=1;
    i:=0;
     while t<n do
      begin
       inc(i);
       t:=t*10;
      end;
      a:=k mod i;
       b:=k div i;
       c:=t mod n;
        s:=1;
        for j:=1 to b do
         begin
          s:=s*10;
           p:=s mod n;
          end;
           for a:=1 to a do
            q:=q*10;
            tot:=m*q mod n;
            tot:=tot*p  mod n ;
          writeln(output,tot);
         close(input); close(output);
         end.
