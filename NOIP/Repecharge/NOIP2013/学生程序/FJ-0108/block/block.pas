var list:array [0..100000] of longint;
    n,i,sum:longint;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do
 begin
 read(list[i]);
 if list[i]-list[i-1]>0 then inc(sum,list[i]-list[i-1]);
 end;
writeln(sum);
close(input);
close(output);
end.
