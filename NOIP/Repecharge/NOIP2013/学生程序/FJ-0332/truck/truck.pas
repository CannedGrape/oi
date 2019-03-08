var q,n,m,xx,yy,zz,i,j,tot,tx,ty,ans:longint;
    v:array[1..10001]of boolean;
    a,b,d:array[1..100000]of longint;
    c:array[1..10001]of longint;

procedure add(x,y,z:longint);
begin
  inc(tot);
  a[tot]:=y;
  b[tot]:=z;
  d[tot]:=c[x];
  c[x]:=tot;
end;

function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;

procedure search(q,minz:longint);
var i,j:longint;
     now:longint;
begin
  if q=ty then
   begin
     if minz>ans then ans:=minz;
     exit;
   end;
  j:=c[q];
  while j<>0 do
   begin
    now:=a[j];
    if v[now] then
     begin
       v[now]:=false;
          search(now,min(minz,b[j]));
       v[now]:=true;
     end;
    j:=d[j];
    end;
end;

begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out'); rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(xx,yy,zz);
      add(xx,yy,zz);
      add(yy,xx,zz);
    end;
  readln(q);
  for i:=1 to q do
   begin
    readln(tx,ty);
    fillchar(v,sizeof(v),true);
    ans:=-1;
    v[tx]:=false;
    search(tx,100001);
     writeln(ans);
   end;
 close(input);
 close(output);
end.

