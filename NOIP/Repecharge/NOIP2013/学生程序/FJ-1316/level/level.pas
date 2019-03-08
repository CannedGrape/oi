program level (input,output);
var
 a,s,d,e,w,z,y,x,c:integer;
 k:array [1..1000] of integer;

begin
 assign(input,'level.in');
 reset(input);
 assign(output,'level.out');
 rewrite(output);
 readln(a,s);
 z:=0;
 x:=0;
 y:=0;
 for d:=1 to 1000 do
  read(k[d]);
 for e:=2 to 1000 do
  begin
   for w:=3 to 1000 do
   if k[e]=k[w] then
    z:=z+1
  end;
 for c:=2 to 1000 do
  if k[e]>=k[1] then
   x:=x+1;
 y:=x-z;
 write(y);
 close(input);
 close(output);
end.
