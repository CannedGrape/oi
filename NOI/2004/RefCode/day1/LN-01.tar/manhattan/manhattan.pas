  {$I-,Q-,R-,S-}
const fin='manhattan.in';fout='manhattan.out';
      maxn=110;infi=1000000000;
type quenode=record
               x1,y1,x2,y2:longint;
             end;
     backnode=record
                chs,j,k:longint;
              end;
var f:array[0..maxn,1..maxn+1,1..maxn+1] of longint;
    back:array[1..maxn,1..maxn,1..maxn] of backnode;
    costx,costy,dx,dy,cx,rx,ry,brx,bry:array[1..maxn] of longint;
    rm:array[0..1,1..maxn] of longint;
    eva:array[1..maxn,0..1] of longint;
    que:array[1..maxn] of quenode;
    m,n,k,rlt,now:longint;
procedure init;
var i:longint;
    ch:char;
begin
  assign(input,fin);
  reset(input);
  readln(m,n);
  for i:=1 to m do
    begin
      read(ch);
      if ch='W' then
        dx[i]:=0 else
        dx[i]:=1;
    end;
  readln;
  for i:=1 to n do
    begin
      read(ch);
      if ch='N' then
        dy[i]:=0 else
        dy[i]:=1;
    end;
  readln;
  for i:=1 to m do
    read(costx[i]);
  for i:=1 to n do
    read(costy[i]);
  readln(k);
  for i:=1 to k do
    with que[i] do
      readln(x1,y1,x2,y2);
  close(input);
  for i:=1 to n do
    if dy[i]=0 then
      begin
        eva[i,0]:=0;
        eva[i,1]:=costy[i];
      end else
      begin
        eva[i,0]:=costy[i];
        eva[i,1]:=0;
      end;
end;
function find_next:boolean;
var i:longint;
begin
  i:=m;
  while (i>0) and (cx[i]=1) do
    begin
      cx[i]:=0;
      dec(i);
    end;
  if i=0 then exit(false);
  cx[i]:=1;
  exit(true);
end;
function check:boolean;
var i,st,nd,sty,ndy,x,need,want,miny,maxy:longint;
begin
  fillchar(ry,sizeof(dy),$FF);
  for i:=1 to m do
    rx[i]:=dx[i] xor cx[i];
  for i:=1 to n do
    begin
      rm[0,i]:=n+1;
      rm[1,i]:=n+1;
    end;
  now:=0;
  for i:=1 to m do
    if rx[i]<>dx[i] then
      inc(now,costx[i]);
  for i:=1 to k do
    with que[i] do
      begin
        if y1<y2 then
          begin
            miny:=y1;
            maxy:=y2;
            need:=1
          end else
          begin
            miny:=y2;
            maxy:=y1;
            need:=0;
          end;
        if x1<x2 then
          begin
            st:=x1;
            nd:=x2;
            sty:=y1;
            ndy:=y2;
            want:=1;
          end else
          begin
            st:=x2;
            nd:=x1;
            sty:=y2;
            ndy:=y1;
            want:=0;
          end;
        if miny<maxy then
          begin
            x:=st;
            while x<=nd do
              begin
                if rx[x]=need then
                  break;
                inc(x);
              end;
            if x>nd then exit(false);
          end;
        if st=nd then
          continue;
        if rx[st]<>need then
          if ry[sty]<0 then
            ry[sty]:=want else
          if ry[sty]<>want then
            exit(false);
        if rx[nd]<>need then
          if ry[ndy]<0 then
            ry[ndy]:=want else
          if ry[ndy]<>want then
            exit(false);
        if (rx[st]=need) and (rx[nd]=need) and (maxy<rm[want,miny]) then
          rm[want,miny]:=maxy;
      end;
  exit(now<rlt);
end;
procedure make_ans;
var i,j,k,nj,nk:longint;
begin
  brx:=rx;
  j:=n+1;
  k:=n+1;
  for i:=n downto 1 do
    begin
      bry[i]:=back[i,j,k].chs;
      nj:=back[i,j,k].j;
      nk:=back[i,j,k].k;
      j:=nj;
      k:=nk;
    end;
end;
procedure dynamic;
var i,j,k,get0,get1:longint;
begin
  fillchar(f,sizeof(f),$7F);
  f[0,n+1,n+1]:=now;
  for i:=0 to n-1 do
    begin
      for j:=i+1 to n+1 do
        for k:=i+1 to n+1 do
          if f[i,j,k]<infi then
            begin
              if j<rm[0,i+1] then get0:=j else get0:=rm[0,i+1];
              if k<rm[1,i+1] then get1:=k else get1:=rm[1,i+1];
              if (get1>i+1) and (ry[i+1]<>1) and (f[i,j,k]+eva[i+1,0]<f[i+1,n+1,get1]) then
                begin
                  f[i+1,n+1,get1]:=f[i,j,k]+eva[i+1,0];
                  back[i+1,n+1,get1].chs:=0;
                  back[i+1,n+1,get1].j:=j;
                  back[i+1,n+1,get1].k:=k;
                end;
              if (get0>i+1) and (ry[i+1]<>0) and (f[i,j,k]+eva[i+1,1]<f[i+1,get0,n+1]) then
                begin
                  f[i+1,get0,n+1]:=f[i,j,k]+eva[i+1,1];
                  back[i+1,get0,n+1].chs:=1;
                  back[i+1,get0,n+1].j:=j;
                  back[i+1,get0,n+1].k:=k;
                end;
            end;
    end;
  if f[n,n+1,n+1]<rlt then
    begin
      rlt:=f[n,n+1,n+1];
      make_ans;
    end;
end;
procedure main;
begin
  rlt:=infi;
  fillchar(rx,sizeof(rx),0);
  repeat
    if check then
      dynamic;
  until not find_next;
end;
procedure out;
var i:longint;
begin
  assign(output,fout);
  rewrite(output);
  if rlt<infi then
    begin
      writeln('possible');
      writeln(rlt);
      for i:=1 to m do
        if brx[i]=0 then
          write('W') else
          write('E');
      writeln;
      for i:=1 to n do
        if bry[i]=0 then
          write('N') else
          write('S');
      writeln;
    end else
      writeln('impossible');
  close(output);
end;
begin
  init;
  main;
  out;
end.
