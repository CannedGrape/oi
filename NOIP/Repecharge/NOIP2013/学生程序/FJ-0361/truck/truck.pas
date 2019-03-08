var
     cost,f,totit,next:array[0..100000] of longint;
     father,x,y,z,list,dis:array[0..100000] of longint;
     flag:array[0..100000] of boolean;
     t,q,xx,yy,n,m,i,j,head,tail,total:longint;
procedure addt(x,y,z:longint);
begin
     inc(total);
     totit[total]:=y;
     cost[total]:=z;
     next[total]:=list[x];
     list[x]:=total;
end;

procedure qsort(l,r:longint);
var
   i,j,p,mid:longint;
begin
    i:=l;j:=r;
     mid:=z[(l+r) div 2];
    repeat
    while (z[i]<mid) do inc(i);
    while (z[j]>mid) do dec(j);
    if i<=j then
    begin
    p:=z[i]; z[i]:=z[j]; z[j]:=p;
    p:=x[i]; x[i]:=x[j]; x[j]:=p;
    p:=y[i]; y[i]:=y[j]; y[j]:=p;
    inc(i); dec(j);
    end;
    until i>j;
    if i<r then qsort(i,r);
    if j>l then qsort(l,j);
end;


function searchfather(x:longint):longint;
begin
    if father[x]=x then exit(x)
    else exit(searchfather(father[x]));
end;

function can(x,y:longint):boolean;
begin
  x:=searchfather(x);
  y:=searchfather(y);
   if x<>y then exit(true)
   else exit(false);
end;

procedure union(x,y:longint);
begin
   x:=searchfather(x);
   y:=searchfather(y);
   father[y]:=x;
end;

function min(x,y:longint):longint;
begin
   if x<y then exit(x) else exit(y);
end;

function bfs(x,y:longint):longint;
var
   v,k:longint;
begin
    head:=0;
    tail:=1;
    fillchar(flag,sizeof(flag),true);
    fillchar(f,sizeof(f),0);
    fillchar(dis,sizeof(dis),$7f div 2);
    f[1]:=x;
    flag[x]:=false;
    while (head<>tail) do
    begin
     inc(head);
     v:=f[head]; k:=list[v];
      while (k<>0) do
      begin
       if flag[totit[k]] then
       begin
        dis[totit[k]]:=min(dis[v],cost[k]);
        inc(tail);
        f[tail]:=totit[k];
        flag[totit[k]]:=false;
        if totit[k]=y then exit(dis[y]);
       end;
      k:=next[k];
      end;
    end;
    if dis[y]>1000000 then exit(-1)
    else exit(dis[y]);
end;

begin
assign(input,'truck.in');
assign(output,'truck.out');
reset(input); rewrite(output);
    readln(n,m);
   for i:=1 to m do
    readln(x[i],y[i],z[i]);
    qsort(1,m);
   t:=0;
    for i:=1 to n do
     father[i]:=i;
   for i:=m downto 1 do
   begin
     if can(x[i],y[i]) then
     begin
     union(x[i],y[i]);
     inc(t);
     addt(x[i],y[i],z[i]);
     addt(y[i],x[i],z[i]);
     end;
     if t=n-1 then break;
   end;

    readln(q);
    for  i:=1 to q do
  begin
    readln(xx,yy);
    writeln(bfs(xx,yy));
  end;

close(input); close(output);
end.
