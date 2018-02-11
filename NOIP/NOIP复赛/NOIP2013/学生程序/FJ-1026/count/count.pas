program count;
var a:array[0..8]of byte; x,i,j:byte; ans,n,k:longint;
begin
  assign(input,'count.in'); reset(input);
  assign(output,'count.out'); rewrite(output);
  readln(n,x); ans:=0;
  a[0]:=1; a[1]:=1;
  for k:=1 to n do
  begin
    while a[a[0]+1]>0 do inc(a[0]);
    for i:=1 to a[0] do if a[i]=x then inc(ans);
    inc(a[1]); j:=1;
    while a[j]>=10 do begin a[j]:=a[j] div 10; inc(a[j+1]); inc(j); end;
  end;
  writeln(ans);
  close(input); close(output);
end.
