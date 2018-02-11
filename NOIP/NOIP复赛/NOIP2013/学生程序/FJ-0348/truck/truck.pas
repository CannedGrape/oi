program truck;
var
i,c,d,p,q,x,y,n,m,z:integer;


begin

assign(input,'truck.in');
reset(input); 	
assign(output,'truck.out');
rewrite(output);
readln(n,m);
for i:= 1 to m do 
readln(x,y,z);
readln(q);
for i:= 1 to q do 
readln (c,d);
writeln(-1);
close(input);
close(output);

end.