program xxx;
const maxn:longint=1000000000;
var a,c:array [1..10000] of longint;
 b:array [1..1000000] of longint;
 now,minn,i,j,k,n,m,standred,d,s,t:longint;
 total,ds1,ds2,dt1,dt2:longint; flag:boolean;
 ans:array [1..1000000] of longint;
function min(x,y:longint):longint;
begin
 if x>y then exit(y) else exit(x);
end;
begin
 assign(input,'classroom.in');
 assign(output,'classroom.out');
 reset(input); rewrite(output);
 read(n,m);
 for i:=1 to n do
  read(b[i]);
 standred:=trunc(sqrt(n));
 for i:=1 to standred+10 do
  a[i]:=maxn;
 i:=1;
 while i<=n do
  begin
   if i mod standred=1 then inc(now);
   a[now]:=min(a[now],b[i]);
   inc(i);
  end;
 flag:=true;
 for i:=1 to m do
  begin
   read(d,s,t);
   ds1:=(s-1) div standred;
   ds2:=(s-1) mod standred+1;
   dt1:=(t-1) div standred;
   dt2:=(t-1) mod standred+1;
   minn:=maxn;
   for j:=ds1*standred+ds2 to (ds1+1)*standred do
    if b[j]+c[ds1+1]<minn then minn:=b[j]+c[ds1+1];
   for j:=ds1+2 to dt1 do
    if a[j]+c[j]<minn then minn:=a[j]+c[j];
   for j:=dt1*standred+1 to dt1*standred+dt2 do
    if b[j]+c[dt1+1]<minn then minn:=b[j]+c[dt1+1];
   if minn>=d then
    begin
     for j:=ds1*standred+ds2 to (ds1+1)*standred do
      begin
       b[j]:=b[j]-d; if b[j]<a[ds1+1] then a[ds1+1]:=b[j];
      end;
     for j:=ds1+2 to dt1 do c[j]:=c[j]-d;
     for j:=dt1*standred+1 to dt1*standred+dt2 do
      begin
       b[j]:=b[j]-d; if b[j]<a[dt1+1] then a[dt1+1]:=b[j];
      end;
    end
   else
    begin
     flag:=false;
     writeln(-1);
     writeln(i);
     break;
    end;
  end;
 if flag then write(0);
 close(input); close(output);
end.
