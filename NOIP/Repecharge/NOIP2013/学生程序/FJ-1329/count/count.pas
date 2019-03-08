program count(input,output);
var
 n,j,s,i,x,m:longint;
begin
 assign(input,'count.in');  reset(input);
 assign(output,'count.out');  rewrite(output);
 read(n,x);
 begin
 for i:=1 to n do
 begin
  m:=i;
  while m>0 do
   begin
    if (m mod 10)=x then j:=j+1;
    m:=m div 10;
   end;
  end;
  end;
 writeln(j);
 close(input);
 close(output);
end.



