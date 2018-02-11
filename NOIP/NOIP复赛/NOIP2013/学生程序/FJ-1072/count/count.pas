PROGRAM a1(input,output);
var
  n:longint;
  x,a,i:integer;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  read(n);read(x);
  close(input);
  a:=0;
   for i:=1 to n do
   if (i=x)or(i mod 10=x)or(i div 10=x)
    then a:=a+1;
  if (n>=100)and(n<1000)
    then begin
         if (i mod 100=x)or(i div 100=x)
          then a:=a+1;
         end;
  writeln(a);
  close(output);
end.