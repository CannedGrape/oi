program count;
var n,x,i,j,k,l:longint;
    f1,f2:text;
begin
  assign(f1,'count.in');
  assign(f2,'count.out');
  reset(f1);
  rewrite(f2);
  read(f1,n,x);
  k:=0;
   for i:=1 to n do
   begin
    if (i mod 10)=x then k:=k+1;
    if ((i div 10)mod 10)=x then k:=k+1;
    if ((i div 100)mod 10)=x then k:=k+1;
    if ((i div 1000)mod 10)=x then k:=k+1;
    if ((i div 10000)mod 10)=x then k:=k+1;
    if ((i div 100000)mod 10)=x then k:=k+1;
    if ((i div 1000000)mod 10)=x then k:=k+1;
   end;
  write(f2,k);
close(f1);
close(f2);
end.
