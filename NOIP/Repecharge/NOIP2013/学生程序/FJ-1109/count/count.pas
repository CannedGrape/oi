var a,x,i,k,t:integer;
    m,n,o,y,z:longint;
begin
 assign(input,'count.in');
 assign(output,'count.out');
 reset(input);
 rewrite(output);
 readln(n,x);
  m:=n;
  a:=1;
  for i:=1 to 6 do
   begin
     m:=m div 10;
     if(m=0)then break;
     a:=a+1;
   end;
  if(a=1)and(x<>0)then
   begin
    z:=1;
    halt;
   end
  else if(x=0) then
   begin
    z:=0;
    halt;
   end;
  for k:=11 to n do
   begin
    y:=1;
    o:=k;
    while o>9 do
     begin
      y:=y*10;
      o:=o div 10;
     end;
    o:=k;
    repeat
     if(o div y=x)then t:=t+1;
     y:=y div 10;
    until y<2;
    if(o mod 10=x)then t:=t+1;
    z:=z+t;
    t:=0;
   end;
  if(x=1)then z:=z+2
  else z:=z+1;
  write(z);
  close(input);
  close(output);
end.
