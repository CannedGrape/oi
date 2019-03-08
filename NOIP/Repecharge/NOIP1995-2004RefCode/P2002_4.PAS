program p02_4(input,output);{过河卒的路径数}
const maxn=20;
    dx:array[1..8] of integer=(2,1,-1,-2,-2,-1,1,2);
    dy:array[1..8] of integer=(1,2,2,1,-1,-2,-2,-1);
var f:array[0..maxn,0..maxn,1..12] of integer;
    i,j,k,n,m,x,y:integer;

procedure add(i,j:integer);
var c,k:integer;
begin
     c:=0;k:=1;
     while k<=12 do begin
         f[i,j,k]:=f[i-1,j,k]+f[i,j-1,k]+c;
         c:=f[i,j,k] div 10;
         f[i,j,k]:=f[i,j,k] mod 10;
         k:=k+1;end;
end;

begin
      assign(input,'p4.in');
      reset(input);
      readln(n,m,x,y);
      close(input);
      fillchar(f,sizeof(f),0);
      f[x,y,12]:=-1;
      for i:=1 to 8 do
         if (x+dx[i]<=n) and (x+dx[i]>=0) and (y+dy[i]<=m) and (y+dy[i]>=0) then
            f[x+dx[i],y+dy[i],12]:=-1;
      i:=0;
      while (i<=n) and (f[i,0,12]<>-1) do 
          begin f[i,0,1]:=1;i:=i+1;end;
      while i<n do 
          begin i:=i+1;f[i,0,12]:=-1;end;
      i:=0;
      while (i<=m) and (f[0,i,12]<>-1) do 
          begin f[0,i,1]:=1;i:=i+1;end;
      while i<m do 
          begin i:=i+1;f[0,i,12]:=-1;end;
      for i:=1 to n do
         for j:=1 to m do
            if f[i,j,12]<>-1 then begin
                  if (f[i-1,j,12]<>-1) and (f[i,j-1,12]<>-1) then 
                       add(i,j)
                  else if (f[i-1,j,12]<>-1) then 
                       for k:=1 to 12 do 
                           f[i,j,k]:=f[i-1,j,k]
                  else if (f[i,j-1,12]<>-1) then 
                       for k:=1 to 12 do 
                           f[i,j,k]:=f[i,j-1,k]
                  else f[i,j,12]:=-1; 
            end;
      assign(output,'p4.out');
      rewrite(output);
      k:=12;
      while f[n,m,k]=0 do k:=k-1;
      while k>0 do 
         begin write(f[n,m,k]);k:=k-1;end;
      writeln;
      close(output);
end.
