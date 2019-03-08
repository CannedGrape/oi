var
  n,m,x,y,z,k,i,j,a,b,f:longint;
  v:array[1..10000,1..10000]of longint;
  pd:array[1..10000,1..10000]of boolean;





 function min(a,b:longint):longint;
 begin
 if a<=b then exit(a)
 else    exit(b);
 end;

begin
 assign(input,'truck.in');
 assign(output,'truck.out');
 reset(input);
 rewrite(output);

 readln(n,m);
 fillchar(v,sizeof(v),0);

 for i:=1 to m do
 begin
 read(x,y,z);
 v[x,y]:=z;
 v[y,z]:=z;
 pd[x,y]:=true;
 pd[y,z]:=true;
 end;
for i:=1 to n do
for j:=1 to n do
if not (pd[i,j]) then  v[i,j]:=0;



for i:=1 to n do
for j:=1 to n do
for k:=1 to n do

begin
  if pd[i,k] then
  if pd[k,j] then

  if ((v[i,k]>v[i,j]) and (v[k,j]>v[i,j])) then
  begin
    pd[i,j]:=true;
    pd[j,i]:=true;
    v[i,j]:=min(v[i,k],v[k,j]);
    v[j,i]:=v[i,j];


   end;
 end;



readln(f);
 for i:=1 to f do
 begin
 read(a,b);
 writeln(v[a,b]);
 end;


 close(input);
 close(output);

 end.









