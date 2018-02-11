const   ff='mod';
var 	a,b,i,j,s:longint;
function ans(a,b:longint):longint;
var     i:longint;
begin

s:=0;
for i:=1 to b do begin
	s:=(s+a)mod b;
        if s=1 then exit(i);
        end;
exit(0);
end;

begin
assign(input,ff+'.in');reset(input);
assign(output,ff+'.out');rewrite(output);
readln(a,b);
a:=a mod b;
writeln(ans(a,b));
close(input);close(output);
end.
