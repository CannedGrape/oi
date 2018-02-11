var i,j,k,t,m,n,x,y,z,q,max,mid,min,h:longint;
    a:array[0..100005,1..3] of longint;
    list,d,dis:array[0..10005] of longint;
    b:array[0..30005,1..2] of longint;
    f:array[0..10005] of boolean;
procedure add(x,y,z:longint);
  begin
   inc(t);
   a[t,1]:=x;
   a[t,2]:=z;
   a[t,3]:=list[y];
   list[y]:=t;
  end;
function mi(a,b:longint):longint;
   begin
    mi:=a;
    if mi>b then mi:=b;
   end;
begin
 assign(input,'truck.in'); reset(input);
 assign(output,'truck.out'); rewrite(output);
 readln(n,m); t:=0;  max:=0; min:=100000;
 for i:=1 to m do
  begin
   readln(x,y,z);
   add(x,y,z); add(y,x,z);
   if max<z then max:=z;
   if min>z then min:=z;
  end;
 readln(q);
 for i:=1 to q do readln(b[i,1],b[i,2]);
 d[1]:=1; t:=1; h:=0;
 fillchar(dis,sizeof(dis),0);
 dis[1]:=100005;
 fillchar(f,sizeof(f),true); f[1]:=false;
 while t<>h do
  begin
   h:=(h+1) mod n;
   x:=d[h];
   f[d[h]]:=true;
   y:=list[X];
   while y>0 do
    begin
     if mi(a[y,2],dis[x])>dis[a[y,1]] then
      if f[a[y,1]] then
      begin
       dis[a[y,1]]:=mi(a[y,2],dis[x]);
       t:=(t+1) mod n;
       d[t]:=a[y,1];
       f[a[y,1]]:=false;
      end else dis[a[y,1]]:=mi(a[y,2],dis[x]);
     y:=a[y,3];
    end;
  end;
 for i:=1 to q do
  begin
   k:=mi(dis[b[i,1]],dis[b[i,2]]);
   if k>0 then writeln(k) else writeln(-1);
  end;
  close(input); close(output);
end.
