program expr;
var s,r,n:ansistring;
    a:array [1..100000] of ansistring;
    b:array [1..100000] of longint;
    i,j,k,x,y,h,code:longint;
    c:boolean;
 begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  read(n);
  code:=201;
  j:=1;
  s:='';
  for i:=1 to length(n) do
  begin
   if (n[i]<>'+') and (n[i]<>'*') then a[j]:=a[j]+n[i]
   else
   begin
    inc(j);
    s:=s+n[i];
   end;
  end;
  for i:=1 to j do val(a[i],b[i],code);
  for i:=1 to length(s) do
  begin
   if s[i]='*' then
   begin
    b[i+1]:=b[i]*b[i+1];
    b[i]:=0;
   end;
  end;
  for i:=1 to j do h:=h+b[i];
  str(h,r);
  if length(r)>4 then
  delete(r,1,length(r)-4);
  for i:=1 to length(r) do
  begin
   c:=false;
   for j:=49 to 56 do
   if ord(r[i])=j then
   begin
    k:=i;
    c:=true;
    break;
   end;
   if c then break;
  end;
  if k<=length(r) then
  for i:=k to length(r) do write(r[i])
  else write(0);
  close(input);close(output);
 end.





