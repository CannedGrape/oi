program puzzle;
var
  bo:array[0..35,0..35]of boolean;
  f:array[0..35,0..35]of longint;
  mx,my,kx,ky,i,j,o,n,m,q,ex,ey,sx,sy,tx,ty,x:longint;
function min(x,y:longint):longint;
begin
  if x<y then exit(x);
  exit(y);
end;


begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  fillchar(bo,sizeof(bo),false);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(x);
        if x=1 then bo[i,j]:=true;
      end;
  for o:=1 to q do
    begin
    for i:=1 to n do
      for j:=1 to m do
        f[i,j]:=999999999;
      readln(ex,ey,sx,sy,tx,ty);
      if tx>=sx then
        mx:=1
      else mx:=-1;
      if ty>=sy then
        my:=1
      else my:=-1;
      if ex>=sx then
        kx:=1
      else kx:=-1;
      if ey>=sy then
        ky:=1
      else ky:=-1;
      if mx=kx then
        begin
          if my=ky then
            f[sx,sy]:=abs(ex-sx)+abs(ey-sy)+1;
          if my<>ky then
            f[sx,sy]:=abs(ex-sx)+abs(ey-sy)-1;
        end;
      if mx<>kx then
        begin
          if my=ky then
            f[sx,sy]:=abs(ex-sx)+abs(ey-sy)-1;
          if my<>ky then
            f[sx,sy]:=abs(ex-sx)+abs(ey-sy)-1;
        end;
      if (mx=my) and (my=kx) and (kx=ky) and (abs(tx-sx)+abs(ty-sy)=1) then
        begin
          writeln(abs(ex-sx)+abs(ey-sy));
          continue;
        end;
      for i:=sx to n do
        for j:=sy to m do
          begin
            if (i<>sx) and (j<>sy) and (bo[i,j]) and (bo[i-1,j]) and (bo[i,j-1]) and (bo[i-1,j-1]) then
              begin
                f[i,j]:=min(f[i,j],f[i-1,j]+3);
                f[i,j]:=min(f[i,j],f[i,j-1]+3);
              end;
          end;
      for i:=sx to n do
        for j:=sy downto 1 do
          if (i<>sx) and (j<>sy) and (bo[i,j]) and (bo[i-1,j]) and (bo[i,j+1]) and (bo[i-1,j+1]) then
              begin
                f[i,j]:=min(f[i,j],f[i-1,j]+3);
                f[i,j]:=min(f[i,j],f[i,j+1]+3);
              end;
      for i:=sx downto 1 do
        for j:=sy to m do
          if (i<>sx) and (j<>sy) and (bo[i,j]) and (bo[i+1,j]) and (bo[i,j-1]) and (bo[i+1,j-1]) then
              begin
                f[i,j]:=min(f[i,j],f[i+1,j]+3);
                f[i,j]:=min(f[i,j],f[i,j-1]+3);
              end;
      for i:=sx downto 1 do
        for j:=sy downto 1 do
          if ((i<>sx) or (j<>sy)) and (bo[i,j]) and (bo[i+1,j]) and (bo[i,j+1]) and (bo[i+1,j+1]) then
              begin
                f[i,j]:=min(f[i,j],f[i+1,j]+3);
                f[i,j]:=min(f[i,j],f[i,j+1]+3);
              end;
      if f[tx,ty]=999999999 then
        writeln('-1')
      else writeln(f[tx,ty]);
    end;
  close(input);
  close(output);
end.









