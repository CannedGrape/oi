program flower;
var a,n,x,z,b:integer;
    h:array[0..100]of integer;
    g,l:array[0..100]of boolean;
    y:boolean;
begin
 assign(input,'flower.in');
 reset(input);
 assign(output,'flower.out');
 rewrite(output);
 read(n);
 readln;
 for a:=1 to n do
 read(h[a]);
 x:=0;
 z:=0;
 y:=true;
 h[0]:=0;
 for a:=1 to n do
 begin
 g[a]:=true;
 l[a]:=true;
 end;
 for a:=1 to n do
 begin
 if (h[a]>h[a+1]) and (h[a]>h[a-1]) then y:=false;
 if y=true then
 g[a]:=false;
 end;

 for a:=1 to n do
 begin
 if (h[a]<h[a+1]) and (h[a]<h[a-1])   then y:=false;
 if y=true then
 l[a]:=false;
 end;

 for b:=1 to n do
 begin
 if g[a]=true then inc(x);
 if l[a]=true then inc(z);
 end;
 if x>z then
 write(x)
 else write(z);
 close(input);
 close(output);
 end.