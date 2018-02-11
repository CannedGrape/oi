var
  n,m,k,x,i,j,len,d,y:longint;
  b,c:array[0..20] of longint;
  e:array[0..10000] of longint;
procedure cheng(v:longint);
  //var r:longint;
  begin
    for i:=0 to len-1 do
      begin
        c[i+1]:=c[i+1] + c[i]*v div 10;
        c[i]:=c[i]*v mod 10;
      end;
  end;
function chu(v:longint):boolean;
var r:longint;
begin
  for i:=len downto 1 do
    begin
      b[i-1]:=(b[i]+c[i]) mod v;
    end;
  r:=(b[0]+c[0]) mod v;
  if r=0 then exit(true)
    else exit(false);
end;
procedure chua(v:longint);
  begin
    for i:=k downto 1 do
      e[i-1]:=(e[i] mod v)*10;
    d:=e[0] mod v;
  end;
{procedure cha(x:longint);
var r:longint;
begin
  for i:=0 to 10000 do
    begin
      e[i+1]:=e[i+1]+ e[i];}

{function ch:longint;
  begin}
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  read(n,m,k,x); c[0]:=m;
  len:=20;
  y:=1; //cheng(y);
  while not(chu(n)) do
    begin
      inc(y);
      for i:=1 to len do
       c[i]:=0;
       c[0]:=m;
      cheng(y);
    end;
  e[k]:=1; chua(y);
  j:=(x+m*d) mod n;
  write(j);
  close(input);close(output);
end.

  {for j:=1 to k-1 do
    begin

  if
  //while (y*m mod n)<>0 do inc(y);}

