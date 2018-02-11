var
a:array[1..1000000] of longint;
s:string;
n,x,c,i:longint;
begin
assign(input,'count.in');
reset(input);
assign(output,'count.out');
rewrite(output);
readln(n,x);
s:='';
begin
for i:=1 to n do;
s:=i;
c:=pos(s,x);
copy(s,0,c);
delete(s,0,c-1);
writeln(s);
end;
readln;readln;
close(input);
close(output);

end.

