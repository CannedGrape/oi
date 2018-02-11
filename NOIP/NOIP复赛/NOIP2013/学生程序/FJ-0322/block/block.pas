uses math;
var
  n,i,top,ans,x,y,tt,best,hi:longint;
  a,b,d:array[-1..100010] of longint;
begin
assign(input,'block.in'); reset(input);
assign(output,'block.out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=i;
  end;
  best:=0;
  while true do
    begin
    top:=0;  ans:=0;
    for i:=1 to n+1 do
    begin
      tt:=top;
      while (a[i]<a[d[top]])  and (top<>0) do
      begin
        if (ans<=(i-d[top-1]-1)*a[d[top]])
        then
        begin
          x:=d[tt]-(i-d[top-1]-1)+1;
          y:=d[tt];
          hi:=a[d[top]];
        end;
        ans:=max(ans,(i-d[top-1]-1)*a[d[top]]);
        dec(top);
      end;
      inc(top);
      d[top]:=i;
  end;
    if ans=0 then break;
    best:=best+hi;
    for i:=x to y do
    a[i]:=a[i]-hi;
  end;
  writeln(best);
close(input);  close(output);
end.
