var
a:array[-1..1000] of longint;
b:array[-1..1000] of boolean;
i,j,m,n,o,p,ans:longint;
begin
assign(input,'level.in');reset(input);assign(output,'level.out');rewrite(output);
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),true);
readln(n,m);ans:=0;
for i:=1 to m do
begin
read(o);
for j:=1 to o do begin read(p);inc(a[p]); end;
readln;
end;
for i:=1 to 1000 do if b[a[i]] then  b[a[i]]:=false;
for i:=1 to 1000 do if b[i] then
else inc(ans);
writeln(ans);
close(input);close(output);
end.
