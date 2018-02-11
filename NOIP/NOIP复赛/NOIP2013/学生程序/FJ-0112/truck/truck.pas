var
 m,n,j,i,k,l,min,z,e,s,x,y:longint;
 a:array[1..10000,1..1000]of longint;
function se:boolean;
var
 i,j,k,l:longint;
begin
 se:=false;
 for i:=1 to n do
 begin
  if a[e,i]<>0 then se:=true;
  if a[s,i]<>0 then se:=true;
 end;
 end;

begin
   assign(input,'truck.in');reset(input);
 assign(output,'truck.out');rewrite(output);
min:=maxlongint;
 readln(n,m);
 fillchar(a,sizeof(a),0);
 for i:=1 to m do
 begin
  readln(x,y,z);
  if z<min then min:=z;
  a[x,y]:=z;
  a[y,x]:=z;
 end;
 readln(k);
  for i:=1 to k do
  begin
   readln(s,e);
   if se=false then writeln(-1)
    else writeln(min);
    end;
    close(input);close(output);
    end.
