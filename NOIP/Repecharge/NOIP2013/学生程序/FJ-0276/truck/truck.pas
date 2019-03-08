var
  i,j,h,t,p,q,x,y,z,ac,k,w,n,m,min:longint;
  v:array[0..100100,0..2] of longint;
  e,d,dis:array[0..10100] of longint;
  vis:array[0..10100] of boolean;

begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out'); rewrite(output);

  fillchar(v,sizeof(v),0);
  fillchar(e,sizeof(e),0);

  read(n,m); t:=0;
  for i:= 1 to m do
  begin
    read(x,y,z);
    v[i,0]:=z;
    v[i,1]:=y;
    v[i,2]:=e[x];
    e[x]:=i;
    v[i+m,0]:=z;
    v[i+m,1]:=x;
    v[i+m,2]:=e[y];
    e[y]:=i+m;
  end;

  read(w);
  for k:= 1 to w do
  begin
    read(x,y);

    fillchar(vis,sizeof(vis),1);
    for i:= 1 to n do dis[i]:=-1;
    d[1]:=x; vis[x]:=false;
    dis[1]:=1000000;
    h:=0; t:=1;

    while h<>t do
    begin
      h:=h mod 10007+1;
      p:=e[d[h]];
      while p>0 do
      begin
        q:=v[p,1];
        if dis[d[h]]>v[p,0] then min:=v[p,0] else min:=dis[d[h]];
        if dis[q]<min then
        begin
           dis[q]:=min;
           if vis[q] then
           begin
             t:=t mod 10007+1;
             d[t]:=q;
             vis[q]:=false;
           end;
        end;
        p:=v[p,2];
      end;
      vis[d[h]]:=true;
    end;

    ac:=dis[y];
    writeln(ac);
  end;

  close(input); close(output);
end.







