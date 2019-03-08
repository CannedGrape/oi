program work;
var a:array[0..100011] of longint;
    i,j,n,m,k,ans,num:longint;
    v:boolean;
procedure init;
begin
 assign(input,'flower.in');
 assign(output,'flower.out');
 reset(input);
 rewrite(output);
end;
procedure oover;
begin
 close(input);
 close(output);
end;
begin
 init;
 read(n);
 for i:=1 to n do read(a[i]);
 a[0]:=-1;
 v:=true;ans:=0;
 for i:=1 to n do
 if v then
 if a[i]>a[i-1] then
 begin
  inc(ans);
  v:=false;
 end
 else
 else
 begin
  if a[i]<a[i-1] then
   begin
    inc(ans);
    v:=true;
   end;
 end;
 a[0]:=1 shl 30;
 v:=false;
 num:=0;
 for i:=1 to n do
 if v then
  if a[i]>a[i-1] then
   begin
    inc(num);
    v:=false;
   end
  else
 else
  if a[i]<a[i-1] then
   begin
    inc(num);
    v:=true;
   end;
 if num>ans then ans:=num;
 writeln(ans);
 oover;
end.