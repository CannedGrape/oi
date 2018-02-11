program block;

var
min,a,b,c,n,caozuo:longint;

h:array[1..100001] of longint;

begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
fillchar(h,sizeof(h),0);
readln(n);
for a:=1 to n do read(h[a]);

caozuo:=0;

for a:=1 to n do begin
  b:=a+1;
  min:=h[a];
  while h[b]>0 do begin
    if min>h[b] then min:=h[b];
    inc(b);
  end;
   dec(b);
  caozuo:=caozuo+min;
  for c:=a to b do h[c]:=h[c]-min;

end;

write(caozuo);
close(input);close(output);
end.
