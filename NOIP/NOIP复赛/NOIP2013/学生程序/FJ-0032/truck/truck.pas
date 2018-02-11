var
  n,m,q,x,y,z,tot,max,i:longint;
  c:array[1..110000]of boolean;
  b,next,last,w:array[1..110000]of longint;
  fa:array[0..100000]of longint;
  e:array[1..110000,1..3]of longint;
  o:boolean;
procedure biao(x,y,z:longint);
begin
  inc(tot);
  w[tot]:=z;
  b[tot]:=y;
  next[tot]:=last[x];
  last[x]:=tot;
end;

procedure quick(p,q:longint);
var
  i,j,mid,t:longint;
begin
  i:=p;j:=q;
  mid:=e[(i+j) div 2,3];
  repeat
    while e[i,3]<mid do inc(i);
    while e[j,3]>mid do dec(j);
    if i<=j then
    begin
      t:=e[i,1];e[i,1]:=e[j,1];e[j,1]:=t;
      t:=e[i,2];e[i,2]:=e[j,2];e[j,2]:=t;
      t:=e[i,3];e[i,3]:=e[j,3];e[j,3]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  if j>p then quick(p,j);
  if i<q then quick(i,q);
end;

procedure dfs(z:longint);
var
  i,t:longint;
begin
  if z=y then
  begin
    writeln(max);
    o:=true;
    exit;
  end
  else
  begin
    i:=last[z];
    while (i<>0) and (not o) do
    begin
      if c[b[i]] then
      begin
        t:=max;
        c[b[i]]:=false;
        if w[i]<max then max:=w[i];

        dfs(b[i]);
             c[b[i]]:=true;
        max:=t;
      end;
      i:=next[i];
    end;
  end;
end;


function getfather(i:longint):longint;
begin
  if fa[i]=i then exit(i);
  fa[i]:=getfather(fa[i]);
end;

begin
  assign(input,'truck.in') ;
  assign(output,'truck.out');
  reset(input);
  rewrite(output);
  fillchar(c,sizeof(c),true);
  readln(n,m);
  for i:=1 to n do fa[i]:=i;
  for i:=1 to m do
  begin
    readln(x,y,z);
  //  biao(i*2-1,x,y,z);
 //   biao(i*2,y,x,z);
    e[i*2-1,1]:=x;e[i*2-1,2]:=y;e[i*2-1,3]:=z;
    e[i*2,2]:=x;e[i*2,1]:=y;e[i*2,3]:=z;
  end;
  quick(1,2*m);
  //halt;
  tot:=0;
  for i:=2*m downto 1 do
  begin
    x:=getfather(e[i,1]);
    y:=getfather(e[i,2]);
    if x<>y then
    begin
      fa[fa[x]]:=fa[y];
      biao(e[i,1],e[i,2],e[i,3]);
      biao(e[i,2],e[i,1],e[i,3]);
    end;
  end;
  readln(q);
  for i:=1 to q do
  begin
    max:=maxlongint;
    o:=false;
    readln(x,y);
    dfs(x);
    if not o then writeln(-1);
  end;
  close(input);
  close(output);
end.
