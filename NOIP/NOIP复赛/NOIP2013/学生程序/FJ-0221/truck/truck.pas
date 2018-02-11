//RP++
var n,m,i,j,x,y,z,q,k:longint;
    a:array[0..10000,0..10000] of longint;
    b,c:array[0..30000] of longint;

function akb(a,b:longint):longint;

begin
  if a>b then exit(a)
  else exit(b);
end;

begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);

  readln(n,m);
  fillchar(a,sizeof(a),0);

  for i:=1 to m do begin
    x:=0;y:=0;z:=0;
    readln(x,y,z);
    if (x<y) then
      if a[x,y]<z then a[x,y]:=z;
    if (x>y) then
      if a[y,x]<z then a[y,x]:=z;
  end;

  readln(q);
  for i:=1 to q do readln(b[i],c[i]);

  for i:=1 to n-2 do
    for j:=i+1 to n-1 do
       for k:=j+1 to n do begin
         if (a[i,j]<>0) and (a[j,k]<>0) then
         a[i,k]:=akb(a[i,k],a[i,j]+a[j,k]);
       end;

  for i:=1 to q do begin
    if a[b[i],c[i]]=0 then c[i]:=-1;
    writeln(c[i]);
  end;



  close(input);
  close(output);
end.
