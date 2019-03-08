program truck;
 var x,y,z:array[0..10000] of integer;
 x1,y1:array[0..1000] of integer;
  a:array[0..1000,0..1000] of integer;
  n,m,i,q,j,ans,s,di,qu,se,p,i1,j1,zhen:longint;
  a1:array[0..1000,0..1000] of boolean;
begin
assign(input,'truck.in');
assign(output,'truck.out');
reset(input);
rewrite(output);
 readln(n,m);
 for i:=1 to m do
  readln(x[i],y[i],z[i]);
 readln(q);
 for i:=1 to q do
  readln(x1[i],y1[i]);
 for i:=1 to n do
   begin
    a[x[i],y[i]]:=z[i];
    a[y[i],x[i]]:=z[i];
   end;
 for i:=1 to q do
  begin
  di:=y1[i];
  zhen:=30000;
   while di<>x1[i] do
    begin
     ans:=0;
     se:=0;
     p:=0;
     qu:=di;
     for s:=1 to n do
      if a[s,qu] >=ans then
       begin
        ans:=a[s,qu];
        a1[s,qu]:=true;
        if se=qu then a1[p,se]:=false;
        se:=qu;
        di:=s;
        p:=s;
       end;
      if (s=n)and(ans=0) then
      begin
      zhen:=-1;
      break;
      end;
      end;
   for i1:=1 to n do
    for j1:=1 to n do
      if (a1[i1,j1]=true) and (a[i1,j1]<zhen) then zhen:=a[i1,j1];
    writeln(zhen);
  for i1:=1 to n do
   for j1:=1 to n do
    a1[i1,j1]:=false;
   end;
close(input);
close(output);
end.
