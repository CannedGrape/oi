program ye;
var b,bb:array[0..31,0..31] of boolean;
    i,j,ji,jj,ans,q,n,m,x,ex,ey,sx,sy,tx,ty:longint;
    c:boolean;
procedure move(x,y:longint);
 begin
  if ((x=ex) and (y=ey)) then
   begin
    if (ji<ans) or (ans=0) then ans:=ji;
    exit;
   end;
  inc(ji);
  if (ji>ans) and (ans<>0) then exit;
  bb[x,y]:=false;
  if (x<m) and (bb[x+1,y]) and (b[x+1,y]) then move(x+1,y);
  if (x>1) and (bb[x-1,y]) and (b[x-1,y]) then move(x-1,y);
  if (y<n) and (bb[x,y+1]) and (b[x,y+1]) then move(x,y+1);
  if (y>1) and (bb[x,y-1]) and (b[x,y-1]) then move(x,y-1);
  bb[x,y]:=true;
  dec(ji);
 end;
begin
 assign(input,'puzzle.in'); reset(input);
 assign(output,'puzzle.out'); rewrite(output);
 readln(n,m,q);
 fillchar(b,sizeof(b),false);
 for i:=1 to n do
  begin
   for j:=1 to m do
    begin
     read(x);
     if x=1 then b[i,j]:=true;
    end;
   readln;
  end;
 for i:=1 to q do
  begin
   readln(ex,ey,sx,sy,tx,ty);
   if (sx=tx) and (sy=ty) then writeln('0')
    else
     begin
      ji:=4;
      if (b[tx-1,ty]) then dec(ji);
      if (b[tx+1,ty]) then dec(ji);
      if (b[tx,ty+1]) then dec(ji);
      if (b[tx,ty-1]) then dec(ji);
      if ji>2 then
       begin
        writeln('-1');
        break;
       end;
      ji:=4;
      if (b[sx-1,sy]) then dec(ji);
      if (b[sx+1,sy]) then dec(ji);
      if (b[sx,sy+1]) then dec(ji);
      if (b[sx,sy-1]) then dec(ji);
      if ji>2 then
       begin
        writeln('-1');
        break;
       end;
      ji:=4;
      if (b[ex-1,ey]) then dec(ji);
      if (b[ex+1,ey]) then dec(ji);
      if (b[ex,ey+1]) then dec(ji);
      if (b[ex,ey-1]) then dec(ji);
      if ji=4 then
       begin
        writeln('-1');
        break;
       end;
      if (ji=3) and (((ex+1=sx)and(ey=sy)) or ((ex-1=sx)and(ey=sy)) or ((ex=sx)and(ey+1=sy) or ((ex=sx)and(ey-1=sy)))) then
       if ((ex=tx)and(ey=ty)) then
        begin
         writeln('1');
         break;
        end
        else
         begin
          writeln('-1');
          break;
         end;
      ji:=0;
      ans:=0;
      fillchar(bb,sizeof(bb),true);
      move(sx,sy);
      if ans=0 then writeln('-1')
       else writeln(ans);
     end;
  end;
 close(input); close(output);
 end.
