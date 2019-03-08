var
  map,ans:array[0..1000,0..1000]of longint;
  f:array[0..1000,0..1000]of boolean;
  i,j,k:longint;
  n,m,x,y,z,q:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
function min(a,b:longint):longint;
begin
  if a>b then exit(b) else exit(a);
end;
begin
  assign(input,'truck.in');reset(input);
 assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
   begin
     readln(x,y,z);
     if z>map[x,y] then
      begin map[x,y]:=z;ans[x,y]:=z;end;

      if z>map[y,x] then
      begin map[y,x]:=z;ans[y,x]:=z;end;

     f[x,y]:=true;  f[y,x]:=true;
   end;

  for k:=1 to n do
   for i:=1 to n do
    for j:=1 to n do
     if f[i,k] and f[k,j] then
     begin
     ans[i,j]:=max(ans[i,j],min(ans[i,k],ans[k,j]));
      ans[j,i]:=ans[i,j];
      f[i,j]:=true;
      f[j,i]:=true;
     end;

  {for k:=1 to n do
   for i:=1 to n do
    for j:=1 to n do
     if f[i,k] and f[k,j] then
     begin
      ans[i,j]:=max(ans[i,j],min(ans[i,k],ans[k,j]));
      ans[j,i]:=ans[i,j];
     end; }
  readln(q);
  for i:=1 to q do
   begin
    readln(x,y);
    if ans[x,y]=0 then writeln('-1')
    else writeln(ans[x,y]);
   end;
  close(Input);close(output);
end.
