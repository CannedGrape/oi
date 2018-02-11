program block;
var
ans:integer;
c,d,i,n:longint;
a,h:array[1..100000] of integer;
b,e:boolean;
begin
 assign(input,'block.in');
 reset(input);
 assign(output,'block.out');
 rewrite(output);
 readln(n);
 for i:=1 to n do
  read(h[i]);
 for i:=1 to n do
  a[i]:=0;
  ans:=0;
  c:=1;
  d:=1;
  b:=true;
 repeat
   for i:=n downto 1 do
    if a[i]<h[i] then
     c:=i;
   for i:=c to n+1 do
    begin
     e:=true;
     if (a[i]=h[i]) or (i=n+1) then
      begin
       d:=i;
       e:=false;
      end;
    if e=false then break;
    end;
   b:=true;
   for i:=1 to n do
    if a[i]<h[i] then b:=false;
   if b=false then
   for i:=c to d-1 do
    inc(a[i]);
   if b=false then inc(ans);
  until b=true;
  writeln(ans);
 close(input);
 close(output);
end.
