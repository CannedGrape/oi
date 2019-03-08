program circle;
var
   s,a,i,b,n,m,c,g,al,a1,a2,x:longint;
   k:int64;
begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);
read(n,m,k,x);
for i:=1 to n do
   begin
   a:=(m*i) mod n;
   if a=0 then
      begin
      if a1=0 then
      begin
      b:=i;
      a1:=1;
      end;
      end;
   end;
for i:=1 to 6 do
   begin
      for s:=1 to i do  a:=a*10;
   if (b mod a < 10) then
                     begin
                     c:=b mod a;
                     if a1=0 then
                     begin
                     a:=i;
                     a1:=1;
                     end;
                     end;

   end;
  if a>k then begin
            for i:=1 to k do  s:=s*10;
            al:=(s*m) mod n;
            x:=x+al;
            if x>=n then x:=x-n;
 end;
          else x:=x;




writeln (x);
close(input);
close(output);
end.
