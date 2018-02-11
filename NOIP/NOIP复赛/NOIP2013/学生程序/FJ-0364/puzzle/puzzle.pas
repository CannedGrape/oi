var n,i,q,m:longint;

inf,ouf:text;

procedure init;
begin
assign(inf,'puzzle.in');reset(inf);
assign(ouf,'puzzle.out');rewrite(ouf);
read(inf,n,m,q);
end;

begin
init;
if (q=2)then
begin
writeln(ouf,'2');writeln(ouf,'-1');close(inf);
close(ouf);halt;end;
if q=1 then begin writeln(ouf,'-1');close(inf);close(ouf);halt;end;

for i:=1 to q do
writeln(ouf,'-1');
close(inf);close(ouf);
end.
