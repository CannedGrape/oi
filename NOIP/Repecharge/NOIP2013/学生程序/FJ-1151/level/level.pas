program cheat;
var
a:array[0..1000]of integer;
i,j,ans,n,m,p,q:integer;


begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
readln(n,m);
for i:=1 to m do begin
	read(p);
for j:=1 to p do begin read(q);inc(a[q]);end;
end;
ans:=a[1];
for i:=2  to n do if ans<a[i] then ans:=a[i];
writeln(ans);

close(input);
close(output);
end.