program truck;
uses math;
var
 n,m,i,x,y,z,p:longint;
 w:array[1..1000,1..1000] of longint;

procedure fin;
begin
 assign(input,'truck.in'); reset(input);
 assign(output,'truck.out'); rewrite(output);
end;

procedure fout;
begin
 close(input);
 close(output);
end;

procedure floyd;
var
 i,j,k:longint;
begin
 for k:=1 to n do
  for i:=1 to n do
   for j:=1 to n do
    if (i<>j) and (i<>k) and (j<>k) then
     if w[i,j]<min(w[i,k],w[k,j]) then w[i,j]:=min(w[i,k],w[k,j]);
end;

begin
 fin;
 readln(n,m);
 fillchar(w,sizeof(w),$FF);
 for i:=1 to m do
 begin
  readln(x,y,z);
  w[x,y]:=z;
  w[y,x]:=z;
 end;
 floyd;
 readln(p);
 for i:=1 to p do
 begin
  readln(x,y);
  writeln(w[x,y]);
 end;
 fout;
end.
