program expr;
var
s:ansistring;
ans,h,l:longint;


function get(var h:longint):longint;
var t:string;a:longint;
begin
inc(h);
a:=h;
while (s[h]>='0')and(s[h]<='9') do inc(h);
t:=copy(s,a,h-a);
val(t,get);
get:=get mod 10000;
end;


function cross( var h:longint):longint;
begin
cross:=get(h);

if s[h]='*' then exit(cross*cross(h) mod 10000);
end;

function plus( var h:longint):longint;
begin
plus:=get(h);
if s[h]='*' then exit(plus*cross(h)mod 10000);
end;




begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
readln(s);
h:=0;
l:=length(s);
ans:=get(h);
while h<l do begin if s[h]='+' then ans:=ans+plus(h) else ans:=ans*cross(h);ans:=ans mod 10000;end;
writeln(ans);
writeln;
close(input);
close(output);
end.