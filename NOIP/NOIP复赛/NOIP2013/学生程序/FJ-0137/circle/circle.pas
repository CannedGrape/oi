var
  sum,r,nn,n,y,q:int64;
  m,k,i:longint;
procedure ksm(x:int64);
begin
 while x<>0 do
 begin
    if x mod 2=1 then sum:=sum*r mod q;
    x:=x div 2;
    r:=r*r mod q;
 end;
end;
begin
 assign(input,'circle.in');reset(input);

 assign(output,'circle.out');rewrite(output);

  readln(n,m,k,y);
  if m=0 then begin writeln(y);close(Input);close(output);halt;end;
  if n mod m=0 then
   q:=n div m
  else
  for i:=1 to n do
   begin
    nn:=n;
    nn:=nn*i;
    if nn mod m=0 then
     begin q:=nn  div m;break;end;
   end;

   sum:=1;r:=10;
  ksm(k);
  sum:=sum mod q;
    //writeln(i,' ',sum,' ',q);
    y:=y+1;
    y:=y+m*(sum);
  y:=y mod n;
  y:=y-1;
  if y=-1 then y:=n-1;
  writeln(y);
  close(Input);close(output);
end.
