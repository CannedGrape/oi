program matches;
const
  maxn=24;
  maxm=50000;

var
  a:array [0..maxn] of longint;
  g:array [1..maxn,0..maxm] of longint;
  f,h:array [0..maxm] of longint;
  n,ans:longint;

procedure fileon;
begin
  assign(input,'matches.in');
  assign(output,'matches.out');
  reset(input);
  rewrite(output);
end;

procedure fileoff;
begin
  close(input);
  close(output);
end;

procedure scan;
begin
  readln(n);
end;

procedure print;
begin
  writeln(ans);
end;

procedure dfs(x,now:longint);
var
  i:longint;
begin
  if f[0]=24 then
    begin
      f[0]:=f[0];
    end;
  for i:=0 to 9 do
    if x+a[i]<=n-4 then
      begin
        inc(f[0]);
        f[f[0]]:=now*10+i;
        h[f[0]]:=x+a[i];
        dfs(x+a[i],f[f[0]]);
      end;
end;

procedure main;
var
  i,j,k,t,l,x,y,z,xx,yy,zz:longint;
  flag:boolean;
begin
  ans:=0;
  a[0]:=6;
  a[1]:=2;
  a[2]:=5;
  a[3]:=5;
  a[4]:=4;
  a[5]:=5;
  a[6]:=6;
  a[7]:=3;
  a[8]:=7;
  a[9]:=6;
  fillchar(f,sizeof(f),0);
  for i:=1 to 10 do
    h[i]:=a[i-1];
  for i:=1 to 10 do
    f[i]:=i-1;
  f[0]:=10;
  for i:=1 to 9 do
    dfs(a[i],i);

  fillchar(g,sizeof(g),0);
  for i:=1 to f[0] do
    begin
      inc(g[h[i],0]);
      g[h[i],g[h[i],0]]:=f[i];
    end;
  for i:=1 to n-4 do
    for x:=1 to g[i,0] do
      for j:=1 to n-4 do
        for y:=1 to g[j,0] do
          begin
            xx:=g[i,x];
            yy:=g[j,y];
            zz:=xx+yy;
            k:=n-4-i-j;
            if k<=0 then
              break;
            flag:=false;
            for z:=1 to g[k,0] do
              if g[k,z]=zz then
                flag:=true;
            if flag then
              inc(ans);
          end;
end;

begin
  fileon;
  scan;
  main;
  print;
  fileoff;
end.
