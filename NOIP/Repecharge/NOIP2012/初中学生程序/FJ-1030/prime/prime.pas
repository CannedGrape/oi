program prime;
var n,i,j:longint;
begin
 assign(input,'prime.in');reset(input);
 assign(output,'prime.out');rewrite(output);
 readln(n);
 for i:=2 to trunc(sqrt(n)) do
 if n mod i=0 then
  begin
   writeln(n div i);
   break;
  end;
 close(input);close(output);
end.
