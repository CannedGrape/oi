uses math;
var n,ans,i,j:longint;
    f:array[1..100000,1..2] of longint;
    a:array[1..100000] of longint;
 begin
 assign(input,'flower.in');reset(input);
 assign(output,'flower.out');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  if n<=8300 then begin
  for i:=1 to n do  begin
   f[i,1]:=1;
   f[i,2]:=1;
   for j:=1 to i-1 do begin
    if a[i]>a[j] then f[i,1]:=max(f[i,1],f[j,2]+1);
    if a[i]<a[j] then f[i,2]:=max(f[i,2],f[j,1]+1);
    end;
   end;
  for i:=1 to n do if max(f[i,1],f[i,2])>ans then ans:=max(f[i,1],f[i,2]);
  write(ans);
  end
  else begin



  end;
   close(input);
close(output);
  end.

