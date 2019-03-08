var
 m,i,j,k,l,max,maxx,n:longint;
 a:array[1..100010]of longint;
 procedure sea(st,h:longint);
 var
  ii,jj,v:longint;
 begin
 if st=n then exit;
  if h>max then max:=h;v:=st;
  for ii:=st to n-1 do
   for jj:=ii to n do
    if a[ii]>a[jj] then
    begin
     h:=h+1;

     st:=jj;
     sea(st,h);
     st:=v;
     h:=h-1;
    end;
    end;
 procedure se(st,h:longint);
 var
  ii,jj,v:longint;
 begin
 if st=n then exit;
  if h>maxx then maxx:=h;v:=st;
  for ii:=st to n-1 do
   for jj:=ii to n do
    if a[ii]>a[jj] then
    begin
     h:=h+1;

     st:=jj;
     se(st,h);
     st:=v;
     h:=h-1;
    end;
    end;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
 readln(n);  maxx:=0;max:=0;
 for i:=1 to n do
  read(a[i]);
 sea(1,0);
 se(1,0);
 if max>maxx then writeln(max)
  else writeln(maxx);
  close(input);close(output);
 end.
