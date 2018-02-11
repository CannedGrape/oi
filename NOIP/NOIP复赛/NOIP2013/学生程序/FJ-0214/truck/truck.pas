var
  n,m,i,j,x,y,z,q,start,finish:longint;
  a:array[1..6000,0..1000]of integer;
  w:array[1..4000,1..4000]of longint;
  f:array[1..12010]of longint;
  dis:array[1..6000]of longint;

function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;

procedure spfa(k:longint);
var
  i,head,tail,p:longint;
  used:array[1..6000]of boolean;
begin
  fillchar(used,sizeof(used),false);
  fillchar(dis,sizeof(dis),0);
  head:=0; tail:=1; f[1]:=k; used[1]:=true; dis[1]:=maxlongint;
  repeat
    inc(head);
    head:=((head-1) mod 12005)+1;
    used[head]:=false;
    p:=f[head];
    for i:=1 to a[p,0] do
     begin
       if dis[a[p,i]]<min(dis[p],w[p,a[p,i]]) then
        begin
         dis[a[p,i]]:=min(dis[p],w[p,a[p,i]]);
         if not used[a[p,i]] then
          begin
            inc(tail);
            tail:=((tail-1)mod 12005)+1;
            f[tail]:=a[p,i];
            used[a[p,i]]:=true;
          end;
        end;
     end;
  until head=tail;
  if dis[finish]=0 then writeln(-1) else writeln(dis[finish]);
end;

begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out'); rewrite(output);
  readln(n,m);
  fillchar(w,sizeof(w),false);
  for i:=1 to m do
   begin
     readln(x,y,z);
     w[x,y]:=z;
     w[y,x]:=z;
     inc(a[x,0]);
     a[x,a[x,0]]:=y;
     inc(a[y,0]);
     a[y,a[y,0]]:=x;
   end;
  readln(q);
  for i:=1 to q do
   begin
     readln(start,finish);
     spfa(start);
   end;
  close(input); close(output);
end.
