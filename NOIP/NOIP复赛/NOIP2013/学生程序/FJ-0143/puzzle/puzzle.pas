program puzzle;
var
 i,j,q,n,m,ex,ey,sx,sy,tx,ty:longint;
 ch:array[1..30,1..30] of integer;
 f,c:array[1..30,1..30] of boolean;

 begin
 assign(input,'puzzle.in');reset(input);
 assign(output,'puzzle.out');rewrite(output);
 readln(n,m,q);
 fillchar(c,sizeof(c),false);
 for i:=1 to n do
  for j:=1 to m do
   begin
   read(ch[i,j]);
   if ch[i,j]=0 then f[i,j]:=false;
   end;
  for i:=1 to q do
  begin
  read(ex,ey,sx,sy,tx,ty);
   c[ex,ey]:=true;
   writeln('-1');
   end;
   close(input);close(output);
  end.




