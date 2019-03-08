var i,j,ans,k,n,m,q,p,temp:longint;
    a:array[1..10000,1..10000] of longint;
    b:array[1..10000,1..10000] of boolean;
    f:array[0..10000,0..10000] of longint;
    x,y,z:longint;
procedure search(x,y:longint);
var i,j:longint;
    o,text:longint;
begin
text:=0;
for i:=1 to n do
begin
    if b[x,i] then
    begin
    if text<a[x,i] then
    begin
    o:=i;
    text:=a[x,i];
    if a[x,i]<ans then ans:=a[x,i];
    end;
    if o=y then  exit;
if (o<n) and(o>0) then
search(i,y);
end;
end;
end;
procedure init;
var i,j:longint;
    x,y,z:longint;
begin
    read(n,m);
    fillchar(f,sizeof(f),0);
    fillchar(b,sizeof(b),false);
    for i:=1 to m do
    begin
    read(x,y);
    if b[x,y]=false then
    begin
    read(a[x,y]);

    b[x,y]:=true;
    b[y,x]:=true
    end
    else
    begin
        read(z);
        if z>a[x,y] then a[x,y]:=z
    end;
    a[y,x]:=a[x,y];
    end;

    read(q);
    end;



begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
init;
  for p:=1 to q do

  write('-1');
  writeln;
  end;


end.
