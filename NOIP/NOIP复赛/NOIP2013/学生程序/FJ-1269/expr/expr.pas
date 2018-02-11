program expr;
var a:array[1..10000] of longint;
    s:string;
    x,i,j,y,code:longint;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 read(s);
for i:=1 to length(s) do
 val(s[i],a[i]);
for i:=1 to length(s) do
  if s[i]='*' then
   begin
    a[i]:=a[i+1]*a[i-1];
    x:=a[i]+x;
    a[i-1]:=0;
    a[i+1]:=0;
   end;
for i:=1 to length(s) do
  if s[i]='+' then
   begin
    a[i]:=a[i+1]+a[i-1];
    x:=a[i]+x;
   end;
   s:=char(x);
if x>9999 then
begin
 if ord(s[1])=0 then
  begin
   write(ord(s[2])+ord(s[3])*10+ord(s[4])*100);
   if ord(s[2])=0 then
   begin
    write(ord(s[1])+ord(s[3])*10+ord(s[4])*100);
    if ord(s[3])=0 then
     begin
      write(ord(s[1])+ord(s[2])*10+ord(s[4])*100);
      if ord(s[4])=0 then write(ord(s[1])+ord(s[2])*10+ord(s[3])*100)
       else write(ord(s[1])+ord(s[2])*10+ord(s[3])*100+ord(s[4])*1000);
     end;
   end;
  end;
end
else write(x);
close(input);close(output);
end.
