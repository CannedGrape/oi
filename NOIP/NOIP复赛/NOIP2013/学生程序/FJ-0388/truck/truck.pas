program truck;
var a,b,c,m,n,q,d,e,f,g,h:longint;
x,y,z,xc,yc,jie,kai,fan,zui,you,su:array[1..50000]of longint;
cu:array[1..50000,1..50000]of longint;
begin
{ assign(input,'truck.in');
 reset(input);
 assign(output,'turck.out');}
 rewrite(output);
  f:=0;
  read(n,m);
  for a:=1 to m do
  z[a]:=0;
  for a:=1 to m do
   read(x[a],y[a],z[a]);
  read(q);
  for a:=1 to q do
   read(xc[a],yc[a]);
  for a:=1 to q do
   begin
    d:=xc[a];
    e:=yc[a];
     for b:=1 to q do
      if (x[b]=d) or (y[b]=d)
       then if (y[b]=e) or (x[b]=e) then
        begin
         jie[a]:=z[b];
         fan[a]:=1;
        end
       else
        kai[a]:=1;
   end;
  for a:=1 to m do
   if (kai[a]=1) and (fan[a]<>1) then
    jie[a]:=-1;
  for a:=1 to q do
    if jie[a]>0 then zui[a]:=jie[a] else zui[a]:=-1;
  for a:=1 to m do su[a]:=1;
  for a:=1 to m do
   for c:=1 to m do
    begin
     if (x[a]=x[c]) and (a<>c) then
      begin
       f:=x[a];
       su[f]:=su[f]+1;
      end;
     if (y[c]=y[a]) and (a<>c) then
      begin
       f:=x[a];
       su[f]:=su[f]+1;
      end;
     if (y[c]=x[a]) then
      begin
       f:=x[a];
       su[f]:=su[f]+1;
      end;
    end;
 for a:=1 to q do
  begin
   d:=xc[a];
   e:=yc[a];
   cu[d,e]:=a;
   if (su[a]=1) and (zui[a]>0) then you[a]:=zui[a];



  end;
 for a:=1 to q do
  writeln(you[a]);
{ close(input);
 close(output);}
end.