var
  j,i,p,s,t,n,m,q,x,o:longint;
  a:array[1..100,1..100]of boolean;
  c:array[1..270000,0..4]of longint;
  bu:array[1..30,1..30,1..30,1..30]of boolean;
procedure jia(o,p,v,b,n,m,u:longint);
begin
  inc(t);c[t,0]:=u+1;
  c[t,1]:=o;c[t,2]:=p;
  if (o=n)and(p=m)then
    begin c[t,3]:=v;c[t,4]:=b;end
      else begin c[t,3]:=n;c[t,4]:=m;end;
  if not bu[c[t,1],c[t,2],c[t,3],c[t,4]]then dec(t)
    else bu[c[t,1],c[t,2],c[t,3],c[t,4]]:=false;
end;
function zuo:longint;
begin
  s:=0;t:=1;c[1,0]:=0;
  while s<>t do
    begin
      inc(s);
      if (c[s,3]=o)and(c[s,4]=p)then exit(c[s,0]);
      if (c[s,1]+1<=n)and(a[c[s,1]+1,c[s,2]])then
        jia(c[s,1]+1,c[s,2],c[s,1],c[s,2],c[s,3],c[s,4],c[s,0]);
      if (c[s,1]-1>0)and(a[c[s,1]-1,c[s,2]])then
        jia(c[s,1]-1,c[s,2],c[s,1],c[s,2],c[s,3],c[s,4],c[s,0]);
      if (c[s,2]+1<=m)and(a[c[s,1],c[s,2]+1])then
        jia(c[s,1],c[s,2]+1,c[s,1],c[s,2],c[s,3],c[s,4],c[s,0]);
      if (c[s,2]-1>0)and(a[c[s,1],c[s,2]-1])then
        jia(c[s,1],c[s,2]-1,c[s,1],c[s,2],c[s,3],c[s,4],c[s,0]);
    end;
  zuo:=-1;
end;

begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
  read(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(x);
        if x=1 then a[i,j]:=true else a[i,j]:=false;
      end;
  for i:=1 to q do
    begin
      fillchar(bu,sizeof(bu),true);
      read(c[1,1],c[1,2],c[1,3],c[1,4],o,p);
      bu[c[1,1],c[1,2],c[1,3],c[1,4]]:=false;
      writeln(zuo);
    end;
close(input);close(output);
end.
