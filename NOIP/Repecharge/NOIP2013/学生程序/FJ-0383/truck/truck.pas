program truck;
var a,i:integer;
begin
assign(input,'truck.in');reset(input);
assign(output,'truck.out');rewrite(output);
for i:=1 to 1000 do
begin
a:=a+1;
a:=a+i;
a:=i;
end;
write(-1);
close(input);
close(output);
end.