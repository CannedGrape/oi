program exam1;
 var i,j,k,l,m,n,p:longint;
     x,y,z:int64;
     a,b:longint;
     o,q:integer;
 begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
  read(n,p);
  x:=-maxlongint;y:=-maxlongint;z:=-maxlongint;o:=0;q:=0;
  for i:=1 to n do
   begin
    read(a);
    if (o=0) then
     begin x:=a;o:=1; end
    else
     if a+x>x then x:=x+a;
    if (q=0) then
     begin y:=x;q:=1;z:=x+y; end
    else
     begin
      if z>y then y:=z;
      if x+y>z then z:=x+y;
     end;
   end;
  if y<0 then begin write('-');y:=abs(y); end;
  write(y mod p);
close(input);close(output);
 end.

