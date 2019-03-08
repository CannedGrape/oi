var s:array[1..1000,1..1000] of longint;
    x,y,q,m,n,z,i,j,k,t:longint;
    b:array[1..1000,1..1000] of boolean;

function min(a,b:longint):longint;
begin
  if a>b then exit(b) else exit(a);
end;

begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out'); rewrite(output);
  readln(n,m);
  fillchar(s,sizeof(s),$7F);
  for i:=1 to m do
   begin
    readln(x,y,z);
    s[x,y]:=z; s[y,x]:=z;
    b[x,y]:=true; b[y,x]:=true;
    //inc(a[x]); f[x,a[x]]:=y; inc(a[y]); f[y,a[y]]:=x;
   end;
  readln(q);
  for i:=1 to n do s[i,i]:=0;
  for k:=1 to n do
  for i:=1 to (n div 2+1) do
   for j:=1 to n do
    if (b[i,k]) and (b[k,j]) and (i<>j) and (s[i,j]<min(s[i,k],s[k,j])) then
    begin
     s[i,j]:=min(s[i,k],s[k,j]);
     b[i,j]:=true;
    end;

  for i:=1 to q do
   begin
    readln(x,y);
    if s[x,y]<>2139062143 then writeln(s[x,y]) else writeln(-1);
   end;
  close(input); close(output);
end.
