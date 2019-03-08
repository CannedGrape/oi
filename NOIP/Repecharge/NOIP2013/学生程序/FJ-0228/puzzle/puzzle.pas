type cc=record x,y:longint;end;
var
  i,j,m,n,o,p,k,l,r:longint;
  line:array [0..1000000] of record a,b:cc;end;
  map:array [0..31,0..31] of boolean;
  flag:array [1..30,1..30,1..30,1..30] of longint;
  c,t:cc;tt:boolean;
  st:array [1..4] of cc;
begin
  assign(input,'puzzle.in');reset(input);assign(output,'puzzle.out');rewrite(output);
  read(n,m,p);
  fillchar(map,sizeof(map),false);
  st[1].x:=0;st[1].y:=1;st[2].x:=0;st[2].y:=-1;st[3].x:=1;st[3].y:=0;st[4].x:=-1;st[4].y:=0;
  for i:=1 to n do for j:=1 to m do
  begin
    read(k);if k=1 then map[i,j]:=true;
  end;
  for i:=1 to p do
  begin
    filldword(flag,810000,maxlongint shl 1+1);
    with line[1] do read(a.x,a.y,b.x,b.y,c.x,c.y);
    l:=0;r:=1;with line[1] do flag[a.x,a.y,b.x,b.y]:=0;
    tt:=false;
    repeat
      inc(l);
      with line[l] do
      begin
        for j:=1 to 4 do
        begin
          t.x:=a.x+st[j].x;t.y:=a.y+st[j].y;
          if map[t.x,t.y] then
            if (t.x=b.x) and (t.y=b.y) then
              if flag[b.x,b.y,a.x,a.y]=-1 then
              begin
                inc(r);line[r].a:=b;line[r].b:=a;
                flag[b.x,b.y,a.x,a.y]:=flag[a.x,a.y,b.x,b.y]+1;
                if (a.x=c.x) and (a.y=c.y) then
                begin
                  tt:=true;break;
                end;
              end else
            else
              if flag[t.x,t.y,b.x,b.y]=-1 then
              begin
                inc(r);line[r].a:=t;line[r].b:=b;
                flag[t.x,t.y,b.x,b.y]:=flag[a.x,a.y,b.x,b.y]+1;
              end;
        end;
      end;
      if tt then break;
    until l=r;
    if tt then with line[r] do writeln(flag[a.x,a.y,b.x,b.y])
    else writeln(-1);
  end;
  close(input);close(output);
end.
