type rec=record
     x,y:longint;
     end;
const f1:array [1..4] of longint=(0,0,-1,1);
      f2:array [1..4] of longint=(1,-1,0,0);
var map:array [0..31,0..31] of boolean;
    dir:array [0..901] of rec;
    bo1,bo2:boolean;
    f:array [0..31,0..31] of boolean;
    n,m,q,i,j,k,len,ans,l,r,mm,p:longint;
    e,s,t,now:rec;
procedure bfs;
var que:array [0..901] of rec;
    tim,las:array [0..901] of longint;
    l,r,i,j,k,x,y,p:longint;
begin
  l:=0; r:=1; que[0]:=dir[1]; tim[0]:=1; las[0]:=0;
  f[que[0].x,que[0].y]:=false;
  while l<r do
    begin
      for i:=1 to 4 do
        begin
          x:=que[l].x+f1[i];
          y:=que[l].y+f2[i];
          if (not map[x,y]) or (not f[x,y]) then continue;
          que[r].x:=x;
          que[r].y:=y;
          tim[r]:=tim[l]+1;
          las[r]:=l;
          f[x,y]:=false;
          if (x=t.x) and (y=t.y)
          then
            begin
              len:=tim[r];
              k:=r;
              for j:=len downto 2 do
                begin
                  dir[j]:=que[k];
                  k:=las[k];
                end;
              exit;
            end;
          inc(r);
        end;
      inc(l);
    end;
end;
function bfs1:longint;
var que:array [0..901] of rec;
    tim:array [0..901] of longint;
    l,r,i,j,k,x,y:longint;
begin
  l:=0; r:=1; que[0]:=e; tim[0]:=1;
  f[que[0].x,que[0].y]:=false;
  if (que[0].x=dir[2].x) and (que[0].y=dir[2].y) then exit(0);
  while l<r do
    begin
      for i:=1 to 4 do
        begin
          x:=que[l].x+f1[i];
          y:=que[l].y+f2[i];
          if (not map[x,y]) or (not f[x,y]) then continue;
          que[r].x:=x;
          que[r].y:=y;
          tim[r]:=tim[l]+1;
          f[x,y]:=false;
          if (x=dir[2].x) and (y=dir[2].y) then exit(tim[r]-1);
          inc(r);
        end;
      inc(l);
    end;
end;
function bfs2(now:longint):longint;
var que:array [0..901] of rec;
    tim:array [0..901] of longint;
    l,r,i,j,k,x,y:longint;
begin
  l:=0; r:=1; que[0]:=dir[now-1]; tim[0]:=1;
  f[dir[now].x,dir[now].y]:=false;
  f[que[0].x,que[0].y]:=false;
  while l<r do
    begin
      for i:=1 to 4 do
        begin
          x:=que[l].x+f1[i];
          y:=que[l].y+f2[i];
          if (not map[x,y]) or (not f[x,y]) then continue;
          que[r].x:=x;
          que[r].y:=y;
          tim[r]:=tim[l]+1;
          f[x,y]:=false;
          if (x=dir[now+1].x) and (y=dir[now+1].y) then exit(tim[r]-1);
          inc(r);
        end;
      inc(l);
    end;
  exit(-1);
end;
function bfs3:boolean;
var que:array [0..901] of rec;
    tim:array [0..901] of longint;
    l,r,i,j,k,x,y:longint;
begin
  for j:=1 to n do for k:=1 to m do f[j,k]:=true;
  if len=2 then exit(false);
  l:=0; r:=1; que[0]:=s; tim[0]:=1;
  for i:=1 to len-1 do f[dir[i].x,dir[i].y]:=false;
  while l<r do
    begin
      for i:=1 to 4 do
        begin
          x:=que[l].x+f1[i];
          y:=que[l].y+f2[i];
          if (not map[x,y]) or (not f[x,y]) then continue;
          que[r].x:=x;
          que[r].y:=y;
          tim[r]:=tim[l]+1;
          f[x,y]:=false;
          if (x=t.x) and (y=t.y) {and (not ((len=2) and (tim[r]=2)))}
          then exit(false);
          inc(r);
        end;
      inc(l);
    end;
  exit(true);
end;
function bfs4:boolean;
var que:array [0..901] of rec;
    l,r,i,j,k,x,y:longint;
begin
  for j:=1 to n do for k:=1 to m do f[j,k]:=true;
  if len<>2 then exit(false);
  l:=0; r:=1; que[0]:=e;
  f[dir[1].x,dir[1].y]:=false;
  f[que[0].x,que[0].y]:=false;
  while l<r do
    begin
      for i:=1 to 4 do
        begin
          x:=que[l].x+f1[i];
          y:=que[l].y+f2[i];
          if (not map[x,y]) or (not f[x,y]) then continue;
          que[r].x:=x;
          que[r].y:=y;
          f[x,y]:=false;
          if (x=t.x) and (y=t.y) then exit(true);
          inc(r);
        end;
      inc(l);
    end;
  exit(false);
end;
begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);
rewrite(output);

  readln(n,m,q);
  fillchar(map,sizeof(map),false);
  for i:=1 to n do
    for j:=1 to m do begin read(k); if k=1 then map[i,j]:=true; end;
  for i:=1 to q do
    begin
      for j:=1 to n do for k:=1 to m do f[j,k]:=true;
      readln(e.x,e.y,s.x,s.y,t.x,t.y);
      len:=1;
      dir[1]:=s;
      bfs;
      for j:=1 to n do for k:=1 to m do f[j,k]:=true;
      ans:=bfs1;
      for j:=1 to n do for k:=1 to m do f[j,k]:=true;
      bo1:=bfs3;
      bo2:=bfs4;
      if not((bo1) or (bo2)) then begin writeln(-1); continue; end;
      //*******************
      //writeln(bfs3); writeln(bfs4);
      //writeln;
      //writeln(len);
      //for j:=1 to len do writeln(dir[j].x,' ',dir[j].y);
      //writeln;
      //writeln(ans);
      //writeln;
      //*******************
      p:=2;
      while (p<=len) do
        begin
          inc(ans);
          if p=len
          then begin inc(p); continue; end;
          for j:=1 to n do for k:=1 to m do f[j,k]:=true;
          mm:=bfs2(p);
          if mm=-1
          then begin ans:=mm; break; end else ans:=ans+mm;
          inc(p);
        end;
      writeln(ans);
    end;

close(input);
close(output);
end.
