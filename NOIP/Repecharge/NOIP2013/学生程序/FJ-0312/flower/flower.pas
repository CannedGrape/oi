program flower;
var i,n,temp,ans,r:longint;
    h,s,red,green:array[0..100005]of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x);
  exit(y);
end;
function flower(x:longint):longint;
var i,max1,max2,last,g1,r1:longint;
begin
  if n<=2 then exit(1);
  g1:=0;r1:=0;
  for i:=1 to n do
   if h[i]<=x then
   begin if g1=0 then g1:=i; s[i]:=1;end//green
   else begin if r1=0 then r1:=i;s[i]:=2;end; //red
  max1:=1;
  if g1>0 then
  begin
    last:=s[g1];
    for i:=g1+1 to n do
    if s[i]<>last then begin max1:=max1+1;last:=s[i];end;
  end;
  max2:=1;
  if r1>0 then
  begin
    last:=s[r1];
    for i:=r1+1 to n do
    if s[i]<>last then begin max2:=max2+1;last:=s[i];end;
  end;
  flower:=max(max1,max2);
end;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(h[i]);
    if h[i]>r then r:=h[i];
  end;
  ans:=1;
  for i:=0 to r do
  begin
    temp:=flower(i);
    if temp>ans then ans:=temp;
  end;
  write(ans);
  readln;
close(input);close(output);
end.
