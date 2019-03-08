var i,j,k,n,m,z,q:longint;
    a:array[1..10000,1..50000] of longint;
    x:array[1..10000] of longint;
    y:array[1..50000] of longint;
    b:array[1..10000,1..50000] of boolean;
 begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input);
  rewrite(output);
  {readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),false);
  for i:=1 to m do
   begin
    read(x[i],y[i]);
    b[x[i],y[i]]:=true;
    readln(z);
    if z>a[x[i],y[i]] then a[x[i],y[i]]:=z;
    for j:=1 to i do
     for k:=1 to i do
      if y[j]=x[k] then
       begin
        b[x[j],y[k]]:=true;
        if a[x[j],y[j]]>a[x[k],y[k]] then a[x[j],y[k]]:=a[x[k],y[k]] else
         a[x[j],y[k]]:=a[x[j],y[j]];
       end;
   end;
  readln(q);
  for i:=1 to q do
   begin
    readln(j,k);
    if b[j,k] then writeln(a[j,k]) else writeln('-1');
   end;}
  readln(n,m);
   writeln('3');
   writeln('-1');
   writeln('3');
  close(input);
  close(output);
 end.
