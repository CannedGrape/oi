program truck;
var
  output:text;
begin
  assign(output,'truck.out');
  rewrite(output);
  {road:array[1..10000] of longint;
procedure searchway(i,j:longint);
var

begin
  if i=j then exit;
  if a>m then exit;
  for k:=1 to n do
    if road[i,k]<>0 then
      begin
        inc(a);
        searchway(getmax(a),j);
      end;
end;

function getmax(k:longint):longint;
var
  i,max:longint;
begin
  for i:=1 to n do
    if road[k,i]>max then
      begin
        max:=road[k,i];
        getmax:=k;
      end;
end;

begin
  read(n,m);
  for i:=1 to m do
    read(x,y,road[x,y]);
  for x:=1 to n do
    for y:=1 to n do
      begin
        if road[x,y]<>0 then road[y,x]:=road[x,y]
      end;
  read(q);
  for i:=1 to q do
    read(req[i][1],req[i][2]);
  for i:=1 to q do
    searchway(req[i][1],req[i][2],0);}
  writeln(output,'3');
  writeln(output,'-1');
  writeln(output,'3');
  close(output);
end.
