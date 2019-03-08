var cost:Array[0..10000,0..10000]of longint;
    closest,lowcost:Array[0..10000]of longint;
    h,x0,q,yxx,yxk,j,k,ans,x,y,z,i,n,m,max:longint;
    a:array[0..10000,0..10000]of boolean;
    c:Array[0..10000]of boolean;
    ok1,ok2:boolean;
procedure work(xx,yy,kk:longint);
var ii:longint;
begin
  if xx=yy then writeln(kk)
  else
  begin
    for ii:=1 to n do
    if a[ii,xx]=true then
    begin
      a[xx,ii]:=false;
      a[ii,xx]:=false;
      h:=ii;
      if cost[ii,xx]<kk then  work(h,yy,cost[ii,xx])
      else work(h,yy,kk);
      a[xx,ii]:=true;
      a[ii,xx]:=true;
    end;
  end;

end;
begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input); rewrite(output);
  readln(n,m);
  fillchar(cost,sizeof(cost),0);
  fillchar(a,sizeof(a),false);
  ans:=0;
  for i:=1 to m do
  begin
    readln(x,y,z);
    if z>cost[x,y]then
    begin
      cost[x,y]:=z;
      cost[y,x]:=z;
    end;
  end;
  fillchar(c,sizeof(c),false);
  for i:=1 to n do
  for j:=1 to n do
  begin
    if  cost[i,j]>0 then begin c[j]:=true; c[i]:=true;end;
  end;
  for i:=1 to n do
  begin
   lowcost[i]:=cost[i,1];
   closest[i]:=1;
  end;
  lowcost[1]:=-1;
  for i:=1 to  n-1 do
  begin
    max:=-maxlongint;
    for j:=1 to n do
    if (lowcost[j]>max) and (lowcost[j]<>-1) then
    begin
      max:=lowcost[j];
      k:=j;
    end;
    a[k,closest[k]]:=true;
    a[closest[k],k]:=true;
    ans:=ans+lowcost[k];
    lowcost[k]:=-1;
    for j:=1 to n do
    if (k<>j) and (cost[k,j]>lowcost[j])and(lowcost[j]<>-1) then
    begin
     lowcost[j]:=cost[k,j];
     closest[j]:=k;
    end;
  end;

  readln(q);

  for i:=1 to q do
  begin
    readln(x,y);
    ans:=0; ok1:=false; ok2:=false;
    x0:=maxlongint;

    if (c[x]=false) or (c[y]=false) then writeln('-1')
    else
      work(x,y,x0);
  end;
  close(input); close(output);
end.
