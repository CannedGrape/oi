const xx:array[1..4] of integer=(1,0,0,-1);
      yy:array[1..4] of integer=(0,1,-1,0);
var map:array[0..30,0..30] of boolean;
been:array[0..30,0..30,0..30,0..30] of boolean;
tx,ty,nowx,nowy,fa:array[0..1500000] of integer;
step:array[0..1500000] of longint;
i,j,n,m,k,sx,sy,ex,ey,tox,toy,q:integer;
pp:boolean;

procedure bfs;
var h,t,k,gox,goy,j:longint;
temp:boolean;
begin
  h:=0; t:=1;
  tx[1]:=ex; ty[1]:=ey;
  nowx[1]:=sx; nowy[1]:=sy;
  been[ex,ey,sx,sy]:=true;
  temp:=false;
  while h<t do
  begin
   inc(h);
   if (tx[h]=tox) and (ty[h]=toy) then
     begin
       for j:=1 to 4 do
       if (tox+xx[j]=nowx[h]) and (toy+yy[j]=nowy[h]) then
       begin
         pp:=true;
         writeln(step[h]+1);
         temp:=true;
         break;
       end;
       if temp then break ;
     end;
   for k:=1 to 4 do
   if k+fa[h]<>5 then
   if (tx[h]+xx[k]>0) and (tx[h]+xx[k]<=n) and (ty[h]+yy[k]>0) and (ty[h]+yy[k]<=m) then
   if map[tx[h]+xx[k],ty[h]+yy[k]] then
   begin
     if (tx[h]+xx[k]=nowx[h]) and (ty[h]+yy[k]=nowy[h]) then
     begin
       gox:=tx[h]; goy:=ty[h];
     end else begin gox:=nowx[h]; goy:=nowy[h]; end;
     if been[tx[h]+xx[k],ty[h]+yy[k],gox,goy]=false then
     begin
       inc(t);
       tx[t]:=tx[h]+xx[k];
       ty[t]:=ty[h]+yy[k];
       nowx[t]:=gox; nowy[t]:=goy;
       been[tx[t],ty[t],nowx[t],nowy[t]]:=true;
       fa[t]:=k;
       step[t]:=step[h]+1;
     end;
   end;
  end;
  for j:=t downto 1 do
  been[tx[j],ty[j],nowx[j],nowy[j]]:=false;
end;

begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  fillchar(map,sizeof(map),false);
  fillchar(been,sizeof(been),false);
  for i:=1 to n do
  for j:=1 to m do
  begin
    read(k);
    if k=1 then map[i,j]:=true;
  end;
  for i:=1 to q do
  begin
    readln(ex,ey,sx,sy,tox,toy);
    pp:=false;
    bfs;
    if pp=false then writeln(-1);
  end;
  close(input); close(output);
end.



