program truck;
var a,b,n,m,q,z,i,j:longint;
    load,min:array[1..10001,1..10001] of longint;
    f:array[1..10001] of boolean;
    date:array[1..30001,1..2] of longint;

begin
assign(input,'truck.in');
assign(output,'truck.out');
reset(input);
rewrite(output);
fillchar(load,sizeof(load),0);
fillchar(f,sizeof(f),false);
readln(n,m);
for i:=1 to m do
  begin
    readln(a,b,z);
    load[a,b]:=z;
    load[b,a]:=z;
  end;
readln(q);
for i:= 1 to q do readln(date[i,1],date[i,2]);
for i:= 1 to n do
    for j:=1 to n do min[i,j]:=date[i,j];
for i:=1 to n do
 begin
  f[i]:=true;
  for j:=1 to n do if (min[i,j]<>0) and (i<>j) and (f[j]=false) then
    if (min[i,j-1]+min[j-1,j])<min[i,j] then begin min[i,j]:=min[i,j-1]+min[j-1,j]; min[j,i]:=min[i,j];

 end;
 end;
   for i:=1 to q do writeln(min[date[i,1],date[i,2]]);



  close(input);
  close(output);
  end.
