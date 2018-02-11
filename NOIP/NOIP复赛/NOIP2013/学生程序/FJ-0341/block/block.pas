program block;
var a:array[0..100000]of longint;
    n,i,j,k,l,x,y,ans:longint; b:boolean;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
readln(n);
  b:=true;
for i:=1 to n do
 begin
 read(a[i]);
  if b then if a[i]>=a[i-1] then x:=a[i]-y;
  if b then if a[i]<a[i-1] then begin b:=false; ans:=ans+x;end;
  if (not b) then if a[i]<=a[i-1] then y:=a[i];
  if (not b) then if a[i]>a[i-1] then begin b:=true; x:=a[i]-y; end;
  if (i=n) and (a[i]>a[i-1]) then ans:=a[i]-y+ans;
  end;
write (ans);
close(input);
close(output);
end.
