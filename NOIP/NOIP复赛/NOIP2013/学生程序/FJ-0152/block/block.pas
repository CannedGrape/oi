
 program block;
var n,v,a,c,x:integer;
    h,g,l:array[1..100]of integer;
    y,z:boolean;
 begin
 assign(input,'block.in');
 reset(input);
 assign(output,'block.out');
 rewrite(output);
 read(n);
 readln;
 x:=0;
 for a:=1 to n do
 read(h[a]);
 for a:=1 to n do
 g[a]:=0;
 for c:=1 to 100 do
 begin
 z:=true;
 y:=true;
 begin
 for a:=1 to n do
 l[a]:=g[a];
 if z=true then
 begin
 for a:=1 to n do
  if(g[a]<h[a]) then
  inc(g[a]) else z:=false;
  end;
 for a:=1 to n do
 if l[a]<g[a] then y:=false;
  end;
  if y=false then
  begin
  inc(x);
  y:=true;
  end;
  z:=true;
  begin
 for a:=n downto 1 do
 l[a]:=g[a];
 if z=true then
 begin
 for a:=n downto 1 do
 if (g[a]<h[a]) then
  inc(g[a])
  else  z:=false;

  end;
 for a:=n downto 1 do
 if l[a]<g[a] then y:=false;
  if y=false then begin
  inc(x);
  end;
  end;

 end;
 write(x);
 close(input);
 close(output);
 end.
