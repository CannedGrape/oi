var
a:array[1..1000,1..1000] of integer;
min,k,ans,max,last,i,x,y,ls,n,m:longint;
begin
assign(input,'level.in'); reset(input);
assign(output,'level.out'); rewrite(output);
readln(n,m);
fillchar(a,sizeof(a),0);
max:=-1; min:=maxlongint;
for i:=1 to m do
begin
read(ls,last);
if last>max then max:=last;
for x:=2 to ls do begin read(k); for y:=last+1 to k-1 do a[i,y]:=1;
last:=k; end; if last<min then min:=last;
end;
ans:=0;
ls:=0;
for x:=1 to n do
begin
ls:=0;
for y:=1 to n do
ls:=ls+a[y,x];
if ls>ans then ans:=ls
end;
writeln(ans);
close(input);
close(output);
end.
