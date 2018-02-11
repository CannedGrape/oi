program core;
const mn=5000;
var intree:array[1..mn] of boolean;
    mid,map,ecc,dist:array[1..mn,1..mn] of longint;
    w,t1,t2,a,s,b,c,k,max,t,i,j,n:longint;
procedure inst(a,b:longint);
begin
  if (intree[a])and(intree[b]) then exit;
  if mid[a][b]<>0 then begin 
    inst(a,mid[a][b]);
    inst(mid[a][b],b);
  end;
  intree[a]:=true;
  intree[b]:=true; 
end;
function calc(i,j:longint):longint;
begin
  if dist[i][j]>=0 then exit(dist[i][j]);
  if i=j then dist[i][j]:=map[w][i] else begin
    if mid[i][j]<>0 then begin
      t1:=calc(i,mid[i][j]);
      t2:=calc(mid[i][j],j);
      if t1<t2 then dist[i][j]:=t1 else dist[i][j]:=t2; 
    end 
    else dist[i][j]:=maxlongint shr 3;
    if dist[i][j]>map[w][i] then dist[i][j]:=map[w][i];
    if dist[i][j]>map[w][j] then dist[i][j]:=map[w][j];
  end;
  dist[j][i]:=dist[i][j];
  calc:=dist[i][j];
end;
begin
  assign(input,'core.in'); reset(input);
  assign(output,'core.out'); rewrite(output);
  readln(n,s);
  for i:=1 to n do 
    for j:=1 to n do 
      map[i,j]:=maxlongint shr 3;
  for i:=1 to n do 
      map[i][i]:=0;
  for i:=1 to n-1 do begin
    readln(a,b,c);
    map[a,b]:=c;
    map[b,a]:=c;
  end;
  for k:=1 to n do 
    for i:=1 to n do 
      for j:=1 to n do 
        if map[i][k]+map[k][j]<map[i][j] then begin
          mid[i][j]:=k;
          map[i][j]:=map[i][k]+map[k][j];
        end;
  max:=0;
  for i:=1 to n do 
    for j:=i+1 to n do 
      if map[i][j]>max then max:=map[i][j];
  fillchar(intree,sizeof(intree),false);
  for i:=1 to n do 
    for j:=i+1 to n do if map[i][j]=max then 
       inst(i,j);
  fillchar(ecc,sizeof(ecc),0);
  for w:=1 to n do begin
    for i:=1 to n do 
      for j:=1 to n do 
        dist[i][j]:=-1;
    for i:=1 to n do if intree[i] then 
      for j:=i to n do if intree[j] then if map[i][j]<=s then begin
        t:=calc(i,j);
        if t>ecc[i][j] then ecc[i][j]:=t;
      end;
  end;
  max:=maxlongint;
  for i:=1 to n do 
    for j:=i to n do 
      if (intree[i])and(intree[j])and(map[i][j]<=s)and(ecc[i][j]<max) then 
      max:=ecc[i][j];
  writeln(max);
  close(input); close(output);
end.
