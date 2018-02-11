var
ans,pd,ls,i,n,x:longint;
a:array[1..10] of integer;
begin
assign(input,'count.in'); reset(input);
assign(output,'count.out'); rewrite(output);
readln(n,x);
fillchar(a,sizeof(a),0);
ans:=0;
for i:=1 to n do
begin
inc(a[1]);
for ls:=2 to 7 do
begin a[ls]:=a[ls]+(a[ls-1] div 10); a[ls-1]:=a[ls-1]mod 10; end;
pd:=0;
for ls:=7 downto 1 do
begin if a[ls]>0 then pd:=1; if (pd=1)and(a[ls]=x) then inc(ans); end;
end;
writeln(ans);
close(input);
close(output);
end.