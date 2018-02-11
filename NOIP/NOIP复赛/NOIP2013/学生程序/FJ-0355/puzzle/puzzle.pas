Program mxpiii;
Const
   d:array[1..4,1..2] of longint=
   ((0,1),(1,0),(0,-1),(-1,0));
Var
  a,map,color:array[0..40,0..40] of longint;
  vis:array[0..40,0..40] of boolean;
  n,m,q,i,j,Ex,Ey,Sx,Sy,Tx,Ty,ans,x,y,tot:longint;
  flag:boolean;

Procedure dfs(Emx,Emy,now:longint);
Var
  i,j,u,v,Nx,Ny,pre:longint;
Begin
   if now>ans then exit;
   for i:=1 to n do
     for j:=1 to m do
       if a[i][j]=-2 then begin Nx:=i; Ny:=j; break; end;
   if (Nx=Tx) and (Ny=Ty) then
     begin
       if now-1<ans then ans:=now-1;
       flag:=true;
       exit;
     end;
   if now-1+abs(Nx-Tx)+abs(Ny-Ty)>ans then exit;
   for i:=1 to 4 do
     begin
       u:=Emx+d[i][1]; v:=Emy+d[i][2];
       if (u>0) and (u<=n) and (v>0) and (v<=m) then
         if a[u][v]<>0 then
          if not vis[u][v] then
           begin
             pre:=a[Emx][Emy];
             a[Emx][Emy]:=a[u][v];
             a[u][v]:=pre;
             vis[u][v]:=true;
             dfs(u,v,now+1);
             a[u][v]:=a[Emx][Emy];
             a[Emx][Emy]:=-1;
             vis[u][v]:=false;
           end;
     end;
End;

Procedure floodfill(x,y,now:longint);
Var
   i,u,v:longint;
Begin
   color[x][y]:=now;
   for i:=1 to 4 do
    begin
      u:=x+d[i][1]; v:=y+d[i][2];
      if (u>0) and (u<=n) and (v>0) and (v<=m) then
        if map[u][v]<>0 then
          if color[u][v]=0 then
          floodfill(u,v,now);
    end;
End;

Begin
   assign(input,'puzzle.in');
   assign(output,'puzzle.out');
   reset(input);
   rewrite(output);
   fillchar(color,sizeof(color),0);
   tot:=0;
   readln(n,m,q);
   for i:=1 to n do
    begin
     for j:=1 to m do read(map[i][j]);
     readln;
    end;
   for i:=1 to n do
     for j:=1 to m do
       if map[i][j]<>0 then
         if color[i][j]=0 then
           begin
             inc(tot);
             floodfill(i,j,tot);
           end;
   for i:=1 to q do
     begin
       readln(Ex,Ey,Sx,Sy,Tx,Ty);
       if (color[Sx][Sy]<>color[Tx][Ty]) or (color[Ex][Ey]<>color[Sx][Sy]) then
         begin
           writeln(-1);
           continue;
         end;
       fillchar(vis,sizeof(vis),0);
       vis[Ex][Ey]:=true;
       for x:=1 to n do for y:=1 to n do a[x][y]:=map[x][y];
       a[Ex][Ey]:=-1; a[Sx][Sy]:=-2;
       flag:=false; ans:=m*n;
       dfs(Ex,Ey,1);
       if flag then writeln(ans) else writeln(-1);
     end;
   close(input);
   close(output);
End.
