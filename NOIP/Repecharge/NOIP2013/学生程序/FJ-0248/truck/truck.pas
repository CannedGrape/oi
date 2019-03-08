program truck;

var
  n,m,x,y,z,q,i,j,k:longint;
  path:array[1..100000,1..100000]of boolean;
  t,max:array[1..100000,1..100000]of longint;
  a:array[1..1000000] of longint;
function min(a,b:longint):longint;
begin
  if a>b then min:=b
  else min:=a;
end;
procedure init;
var
  i,j,k:longint;
begin
  readln(n,m);
  for i:=1 to m do begin
    readln(x,y,z);
    path[x,y]:=true;
    path[y,x]:=true;
    t[x,y]:=z;
    t[y,x]:=z;
  end;

end;
procedure trans;
var
  i:longint;
begin
  readln(q);
  for i:=1 to q do begin
    readln(x,y);
    if path[x,y]=true then
      a[i]:=t[x,y]
    else
      a[i]:=-1;
  end;

end;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);

  init;

  trans;

  for i:=1 to q do
    writeln(a[i]);

  close(input);
  close(output);


end.
