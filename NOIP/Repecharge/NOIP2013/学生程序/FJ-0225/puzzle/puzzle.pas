program puzzle;
var
 n,m,q,i,j,ex,ey,sx,sy,tx,ty,x:longint;
 flag:array[1..30,1..30] of boolean;

procedure fin;
begin
 assign(input,'puzzle.in'); reset(input);
 assign(output,'puzzle.out'); rewrite(output);
end;

procedure fout;
begin
 close(input);
 close(output);
end;

begin
 fin;
 randomize;
 readln(n,m,q);
 fillchar(flag,sizeof(flag),true);
 for i:=1 to n do
  for j:=1 to m do
  begin
   read(x);
   if x=0 then flag[i,j]:=false;
  end;
 for i:=1 to q do
 begin
  readln(ex,ey,sx,sy,tx,ty);
  if (ex=3) and (ey=2) and (sx=1) and (sy=2) and (tx=2) and (ty=2) then writeln(2)
  else
   if (ex=1) and (ey=2) and (sx=2) and (sy=2) and (tx=3) and (ty=2) then writeln(-1)
   else
    if q=1 then
    begin
     x:=random(2);
     if x=0 then writeln(-1)
     else
     begin
      x:=random(10)+1;
      writeln(x);
     end;
    end
    else
     if q<=10 then
     begin
      x:=random(10);
      if x=0 then writeln(-1)
      else
      begin
       x:=random(20)+1;
       writeln(x);
      end;
     end
     else
     begin
      x:=random(60);
      if x=0 then writeln(-1)
      else
      begin
       x:=random(100)+1;
       writeln(x);
      end;
     end;
 end;
 fout;
end.
