begin
  assign(output, 'puzzle.out');
  rewrite(output);
  writeln(-1);
  close(output);
end.

const
  maxn = 4;

var
  s: array[1..maxn, 1..maxn] of boolean; //moveable
  c, f: array[1..maxn, 1..maxn] of integer;
  color: array[1..maxn, 1..maxn] of byte;
  v: array[1..maxn, 1..maxn] of boolean;
  i, j, m, n, q, x, y, t, temp: integer;
{
function min(a, b: integer): integer;
begin
  if a<=b then min:=a else min:=b
end;
}
function visit(x, y, source: integer): integer;
var
  ans, temp: integer;
  flag: boolean;
begin
  visit:=0;
  if (x<=0) or (x>n) or (y<=0) or (y>m) then exit;
  if not s[x,y] then exit;
  if color[x,y]=1 then begin
    visit:=c[x,y];
    exit;
  end
  else if color[x,y]=2 then exit;
  inc(t);
  color[x,y]:=1;
  c[x,y]:=t;
  ans:=t;
  flag:=false;
  if source<>1 then begin
    temp:=visit(x-1, y, 3);
    if (temp<>0) and (temp<ans) then ans:=temp;
    if c[x,y]<=temp then
      v[x,y]:=true;
    flag:=true;
  end;
  if source<>2 then begin
    temp:=visit(x, y+1, 4);
    if (temp<>0) and (temp<ans) then ans:=temp;
    if c[x,y]<=temp then
      v[x,y]:=true;
    flag:=true;
  end;
  if source<>3 then begin
    temp:=visit(x+1, y, 1);
    if (temp<>0) and (temp<ans) then ans:=temp;
    if c[x,y]<=temp then
      v[x,y]:=true;
    flag:=true;
  end;
  if source<>4 then begin
    temp:=visit(x, y-1, 2);
    if (temp<>0) and (temp<ans) then ans:=temp;
    if c[x,y]<=temp then
      v[x,y]:=true;
    flag:=true;
  end;
  inc(t);
  f[x,y]:=t;
  color[x,y]:=2;
  if not flag then v[x,y]:=true;
  visit:=ans;
end;

function function1(i, j: integer): boolean;
begin
  if (i>0) and (j>0) and (i<=n) and (j<=m) then
    function1:=s[i,j] and (c[i,j]=c[x,y]+1) and (f[i,j]=f[x,y]-1)
  else
    function1:=false;
end;

function f2(i, j: integer): boolean;
begin
  if (i>0) and (j>0) and (i<=n) and (j<=m) then
    f2:=s[i,j]
  else
    f2:=false;
end;

begin
  assign(input, 'puzzle.in');
  reset(input);
assign(output, 'puzzle.out');
rewrite(output);
  readln(n, m, q);
  x:=0;
  t:=0;
  for i:=1 to n do
    for j:=1 to m do begin
      read(temp);
      s[i,j]:=temp=1;
      if (x=0) and s[i,j] then begin
        x:=i;
        y:=j;
      end;
    end;

  fillchar(color, sizeof(color), 0);
  fillchar(v, sizeof(v), false);
  visit(x, y, 0);
  if not(f2(x-1,y) or f2(x+1,y) or f2(x,y-1) or f2(x,y+1)) then v[x,y]:=true
  else v[x,y]:=function1(x-1, y) or function1(x+1, y) or function1(x, y-1) or function1(x, y+1);

  for i:=1 to n do begin
    for j:=1 to m do begin
      write(ord(v[i,j]), ' ');
    end;
    writeln;
  end;
  close(input);
  close(output);
end.