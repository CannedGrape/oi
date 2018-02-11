var
  i,j,m,n,k,l,r,t:longint;
  ro,f:array [0..10000] of longint;
  link:array [0..30000] of record b,la:longint;end;
  fs:array [0..30000] of longint;
  pis:array [0..50000] of record a,b,c:longint;end;
  flag:array [0..30000] of boolean;
procedure qS(l,r:longint);
var
  i,j,x:longint;
begin
  i:=l;j:=r;x:=pis[(l+r) div 2].c;
  repeat
    while pis[i].c>x do inc(i);
    while pis[j].c<x do dec(j);
    if not (i>j) then
    begin
      pis[0]:=pis[i];pis[i]:=pis[j];pis[j]:=pis[0];
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qS(l,j);
  if i<r then qS(i,r);
end;
function fin(k:longint):longint;
var
  i,j:longint;
begin
  i:=f[k];
  while not (i=f[i]) do i:=f[i];
  fin:=i;
  while not (i=f[k]) do
  begin
    j:=f[k];f[k]:=i;k:=j;
  end;
end;
begin
  assign(input,'truck.in');reset(input);assign(output,'truck.out');rewrite(output);
  read(n,m);
  for i:=1 to m do with pis[i] do read(a,b,c);
  read(k);
  fillchar(flag,k+1,true);
  filldword(ro,n+1,0);
  for i:=1 to k do with link[i] do
  begin
    read(j,b);
    la:=ro[j];ro[j]:=i;
  end;
  qS(1,m);l:=0;
  for i:=1 to n do f[i]:=i;
  for r:=1 to m do with pis[r] do if fin(a)=fin(b) then continue
  else
  begin
    inc(l);i:=ro[f[a]];j:=ro[f[b]];
    f[f[b]]:=f[a];
    while not (i=0) do with link[i] do
    begin
      if flag[i] and (fin(b)=f[a]) then
      begin
        fs[i]:=c;flag[i]:=false;
      end;
      i:=la;
    end;
    i:=j;
    while not (i=0) do with link[i] do
    begin
      if flag[i] then
        if fin(b)=f[a] then
        begin
          fs[i]:=c;
          flag[i]:=false;
        end
        else
        begin
          t:=la;
          la:=ro[f[a]];
          ro[f[a]]:=i;
          i:=t;
          continue;
        end;
      i:=la;
    end;
    if l=n-1 then break;
  end;
  for i:=1 to k do if flag[i] then writeln(-1) else writeln(fs[i]);
  close(input);close(output);
end.
