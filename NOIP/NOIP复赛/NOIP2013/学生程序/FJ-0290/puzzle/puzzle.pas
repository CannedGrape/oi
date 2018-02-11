const fx:array[1..4,1..2] of longint=((0,1),(0,-1),(1,0),(-1,0));
Var n,m,q,i,j,x,y,x1,y1,x2,y2,ans,l,r,z1,z2:longint;
    gg:boolean;
    a:array[0..31,0..31] of longint;
    b:array[1..30,1..30,1..30,1..30] of boolean;
    f:array[1..820000,1..5] of longint;
Begin
        Assign(Input,'puzzle.in');Reset(Input);
        Assign(Output,'puzzle.out');Rewrite(Output);
  readln(n,m,q);
  for i:=1 to n do for j:=1 to m do read(a[i,j]);readln;
  for j:=1 to q do
   begin
    ans:=maxlongint;     gg:=false;
    fillchar(b,sizeof(b),0);
    readln(x1,y1,x2,y2,x,y);
    f[1][1]:=x1; f[1][2]:=y1; f[1][3]:=x2; f[1][4]:=y2; f[1][5]:=0;
    l:=0; r:=1;
    while l<r do
     begin
      inc(l);
      for i:=1 to 4 do
       begin
         z1:=f[l][1]+fx[i,1]; z2:=f[l][2]+fx[i,2];
         if a[z1,z2]=0 then continue;
         if (z1=f[l][3]) and (z2=f[l][4]) then
          begin
           if not(b[z1,z2,f[l][1],f[l][2]]) then
            begin
             b[z1,z2,f[l][1],f[l][2]]:=true;
             if (f[l][1]=x) and (f[l][2]=y) then
              begin
               ans:=f[l][5]+1; gg:=true;
               break;
              end;
             inc(r); f[r][1]:=z1; f[r][2]:=z2; f[r][3]:=f[l][1]; f[r][4]:=f[l][2];
             f[r][5]:=f[l][5]+1;
            end;
          end
         else
           if not(b[z1,z2,f[l][3],f[l][4]]) then
            begin
             b[z1,z2,f[l][3],f[l][4]]:=true;
             inc(r); f[r][1]:=z1; f[r][2]:=z2; f[r][3]:=f[l][3]; f[r][4]:=f[l][4];
             f[r][5]:=f[l][5]+1;
            end;
       end;
       if gg then break;
     end;
    if ans=maxlongint then ans:=-1;writeln(ans);
   end;
        Close(Input);Close(Output);
End.
