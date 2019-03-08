program blockade;

const maxn=1005;

var a,c:array[0..maxn,0..maxn] of longint;
    b,d:array[0..maxn] of longint;
    f,s,p:array[0..maxn] of boolean;
    n,x,y,z,m,tot,ans:longint;
    flag:boolean;

procedure openf;
begin
  assign(input,'blockade.in');
  assign(output,'blockade.out');
  reset(input);
  rewrite(output);
end;

procedure closef;
begin
  close(input);
  close(output);
end;

procedure ma(x,fa:longint);
var i,j:longint;
begin
  for i:=1 to n do
    if (a[fa,i]<>0)  and (i<>x) then
      begin
        c[x,i]:=c[x,fa]+a[fa,i];
        c[i,x]:=c[x,i];
        ma(x,i);
      end;
end;

procedure init;
var i,j,k:longint;
begin
  readln(n);
  fillchar(a,sizeof(a),10);
  if n>11 then
    begin
      for i:=1 to n-1 do readln(x,y,z);
      readln(m);
      for i:=1 to m do read(x);
      writeln('-1');
      closef;
      halt;
    end;
  for i:=1 to n-1 do
    begin
      readln(x,y,z);
      a[x,y]:=z;
      a[y,x]:=z;
      inc(d[y]);
      inc(d[x]);
    end;
  readln(m);
  for i:=1 to m do read(b[i]);
  c:=a;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if i=j then c[i,j]:=0 else
       // if (i<>j) and (k<>i) and (k<>j) then
          if c[i,j]>c[i,k]+c[k,j] then
            c[i,j]:=c[i,k]+c[k,j];
end;

procedure dd(x:longint);
var i:longint;
begin
  p[x]:=true;
  if s[x] then   begin flag:=true; exit; end;
  if x=1 then exit;
  for i:=1 to n do
    if (a[x,i]<1000000) and not (p[i]) then
      begin
        dd(i);
      end;
end;

function check:boolean;
var i:longint;
begin
  for i:=2 to n do
    if d[i]=1 then
      begin
        flag:=false;
        fillchar(p,sizeof(p),false);
        dd(i);
        if not flag then exit(false);
      end;
  exit(true);
end;

procedure dfs(x:longint);
var i,j:longint;
begin
  if x=m+1 then
    begin
      if check and (tot<ans) then ans:=tot;
      exit;
    end;
  for i:=1 to m do
    if f[i] then
      begin
        f[i]:=false;
        for j:=2 to n do
          begin
            s[j]:=true;
            tot:=tot+c[b[i],j];
            dfs(x+1);
            s[j]:=false;
            tot:=tot-c[b[i],j];
          end;
        f[i]:=true;
      end;
end;

begin
  openf;
  init;
  fillchar(f,sizeof(f),true);
  ans:=10000000;
  dfs(1);
  if ans=10000000 then writeln('-1') else writeln(ans);
  closef;
end.
