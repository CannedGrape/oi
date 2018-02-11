var n,m,q,i,j,c,x,y,ans,h,t,temp:longint;
    map:array[0..31,0..31]of integer;
    v:array[0..31,0..31]of boolean;
    a:array[1..100000,1..3]of integer;
    dx:array[1..4]of integer=(0,1,0,-1);
    dy:array[1..4]of integer=(1,0,-1,0);
    f1,f2:boolean;
    ex,ey,sx,sy,tx,ty,tex,tey:integer;


begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    begin
      for j:=1 to m do read(map[i,j]);
      readln;
    end;
  for c:=1 to q do
    begin
      readln(ex,ey,sx,sy,tx,ty);
      if (sx=tx)and(sy=ty) then
        begin
         writeln(0);
         continue;
        end;
      f1:=false; f2:=false;
      ans:=-1;

      fillchar(v,sizeof(v),false);
      v[ex,ey]:=true;
      a[1,1]:=ex; a[1,2]:=ey; a[1,3]:=0;
      h:=0; t:=1;
      while h<t do
        begin
          inc(h);
          for i:=1 to 4 do
            begin
              x:=a[h,1]+dx[i];
              y:=a[h,2]+dy[i];
              if (x>0)and(x<=n)and(y>0)and(y<=m)and(not v[x,y])and(map[x,y]<>0) then
                begin
                  inc(t);
                  a[t,1]:=x; a[t,2]:=y; a[t,3]:=a[h,3]+1;
                  v[x,y]:=true;
                  if (x=sx)and(y=sy) then
                    begin
                      sx:=a[h,1]; sy:=a[h,2];
                    end;
                  if (x=tx)and(y=ty) then
                   begin
                     f2:=true;
                     ans:=a[t,3];
                     break;
                   end;
                end;
            end;
          if f2 then break;
        end;
    if not f2 then
      begin
        writeln(-1);
        continue;
      end;

    temp:=map[a[h,1],a[h,2]];
    tex:=a[h,1];
    tey:=a[h,2];
    map[tex,tey]:=0;


   fillchar(v,sizeof(v),false);
   a[1,1]:=sx; a[1,2]:=sy; a[1,3]:=0;
   v[sx,sy]:=true;
   h:=0; t:=1;
   while h<t do
     begin
       inc(h);
       for i:=1 to 4 do
         begin
           x:=a[h,1]+dx[i];
           y:=a[h,2]+dy[i];
           if (x>0)and(x<=n)and(y>0)and(y<=m)and(not v[x,y])and(map[x,y]<>0) then
           begin
             inc(t);
             a[t,1]:=x; a[t,2]:=y; a[t,3]:=a[h,3]+1;
             v[x,y]:=true;
             if (x=tx)and(y=ty) then
             begin
               f1:=true;
               ans:=ans+a[t,3];
               break;
            end;
          end;
       end;
       if f1 then break;
    end;
  if not f1 then
    begin
         writeln(-1);
         continue;
    end;
     writeln(ans);
     map[tex,tey]:=temp;
  end;
  close(input);
  close(output);
end.



