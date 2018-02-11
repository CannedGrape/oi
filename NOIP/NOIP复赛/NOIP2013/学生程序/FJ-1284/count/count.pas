program count;
var i,j,l,n,x,s:longint;
    h:ansistring;
    y:string;
    a:array [1..7] of string;
 begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  read(n,x);
  str(x,y);
  for i:=1 to n do
   begin
    str(i,h);
    for j:=1 to length(h) do
    begin
     a[j]:=copy(h,j,1);
     if a[j]=y then inc(s);
    end;
   end;
   writeln(s);
   close(input);close(output);
 end.