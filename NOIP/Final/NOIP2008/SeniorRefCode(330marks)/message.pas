program message;
const
  maxn=55;

var
  a,g:array [0..maxn,0..maxn] of longint;
  f:array [0..maxn,0..maxn,0..maxn,0..maxn] of longint;
  n,m:longint;

procedure fileon;
begin
  assign(input,'message.in');
  assign(output,'message.out');
  reset(input);
  rewrite(output);
end;

procedure fileoff;
begin
  close(input);
  close(output);
end;

procedure scan;
var
  i,j:longint;
begin
  readln(m,n);
  for i:=1 to m do
    for j:=1 to n do
      read(a[i,j]);
end;

function max(x,y:longint):longint;
begin
  if x>y then
    exit(x)
  else
    exit(y);
end;

procedure print;
begin
  writeln(max(f[m-1,n,m,n-1],f[m,n-1,m-1,n]));
end;

procedure main;
var
  i,j,x,y:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(g,sizeof(g),0);
  x:=0;
  for i:=1 to m do
    for j:=1 to n do
      begin
        inc(x);
        g[i,j]:=x;
      end;
  f[1,1,1,1]:=0;
  f[1,2,2,1]:=a[1,2]+a[2,1];
  for i:=1 to m do
    for j:=1 to n do
      for x:=1 to m do
        for y:=1 to n do
          if f[i,j,x,y]<>0 then
            begin
              if g[i+1,j]<>g[x+1,y] then
                f[i+1,j,x+1,y]:=max(f[i+1,j,x+1,y],f[i,j,x,y]+a[i+1,j]+a[x+1,y]);
              if g[i,j+1]<>g[x,y+1] then
                f[i,j+1,x,y+1]:=max(f[i,j+1,x,y+1],f[i,j,x,y]+a[i,j+1]+a[x,y+1]);
              if g[i+1,j]<>g[x,y+1] then
                f[i+1,j,x,y+1]:=max(f[i+1,j,x,y+1],f[i,j,x,y]+a[i+1,j]+a[x,y+1]);
              if g[i,j+1]<>g[x+1,y] then
                f[i,j+1,x+1,y]:=max(f[i,j+1,x+1,y],f[i,j,x,y]+a[i,j+1]+a[x+1,y]);
            end;

end;

begin
  fileon;
  scan;
  main;
  print;
  fileoff;
end.