var n,k,i:longint; max:int64;
 procedure pd(x:int64);
 var i,j:int64;
 begin
  j:=x mod 10;
  if j=k then inc(max);
  while x div 10>0 do
   begin
    x:=x div 10;
    j:=x mod 10;
    if j=k then inc(max);
   end;
 end;
begin
   assign(input,'count.in');reset(input);
   assign(output,'count.out');rewrite(output);
  readln(n,k);
  for i:=k to n do pd(i);
  writeln(max);
   close(input);close(output);
end.
