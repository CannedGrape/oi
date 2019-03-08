program number222;
var
num:longint;
p,i,n,ans:longint;
spe,gra,ma:longint;


function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;




begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
readln(n,p);
read(num);
spe:=num;
gra:=num;
ma:=num*2;
ans:=num;
for i:=2 to n do begin 
ma:=max(ma,num+spe);
read(num);
gra:=max(ma,spe+gra);
spe:=max(num,spe+num);
ans:=max(ans,gra);
end;
writeln(ans);
close(input);
close(output);
end.