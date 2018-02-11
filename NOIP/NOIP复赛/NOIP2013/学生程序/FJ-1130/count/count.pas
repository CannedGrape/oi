program count;

var
 i,j,k,n,total:longint;

begin
 assign(input,'count.in'); reset(input);
 assign(output,'count.out'); rewrite(output);
 readln(n,k);
 for i:=1 to n do
 begin
  j:=i;
  while j<>0 do
  begin
   if j mod 10=k then inc(total);
   j:=j div 10;
  end;
 end;
 writeln(total);
 close(input); close(output);
end.
