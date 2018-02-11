const
  maxn=10;
var
  n:integer;
  m:array[1..maxn,1..maxn] of integer;
  d1,d2:array[1..maxn,1..maxn] of integer;
  sum:array[1..maxn,1..maxn,1..maxn] of integer;

procedure init;
var
  x,y,p:integer;
  i,j,k:integer;
begin
  readln(n);
  fillchar(m,sizeof(m),0);
  repeat
    readln(x,y,p);
    if (x=0)and(y=0)and(p=0) then break;
    m[x,y]:=p;
  until false;
  {calc sum}
  for i:=1 to n do
  begin
    sum[i,1,1]:=m[i,1];
    for j:=2 to n do
      sum[i,1,j]:=sum[i,1,j-1]+m[i,j];
    for j:=2 to n do
      for k:=j to n do
        sum[i,j,k]:=sum[i,1,k]-sum[i,1,j-1];
  end;
end;

function max(a,b:integer):integer;begin if a>b then max:=a else max:=b; end;

procedure solve;
var
  y1,y2,yy1,yy2,x,r:integer;
begin
  {init}
  for y1:=1 to n do
    for y2:=y1 to n do
      d2[y1,y2]:=sum[n,y1,n];

  for x:=n-1 downto 1 do
  begin
    for y1:=1 to n do
      for y2:=y1 to n do
      begin
        d1[y1,y2]:=-maxint;
        for yy1:=y1 to n do
          for yy2:=max(y2,yy1) to n do
          begin
            if yy1>=y2 then r:=sum[x,y1,yy2]+d2[yy1,yy2]
                       else r:=sum[x,y1,yy1]+sum[x,y2,yy2]+d2[yy1,yy2];
            if r>d1[y1,y2] then d1[y1,y2]:=r;
          end;
      end;
    d2:=d1;
  end;
end;

begin
  init;
  solve;
  writeln(d2[1,1]);
end.
