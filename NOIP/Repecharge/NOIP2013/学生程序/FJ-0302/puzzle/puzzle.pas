program sfaa;
const
 dx:array[1..4]of integer=(0,0,1,-1);
 dy:array[1..4]of integer=(1,-1,0,0);
var i,j,n,m,q,x1,y1,x2,y2,x3,y3,ans,ans2,ans1,min:longint;
    a:array[0..35,0..35]of shortint;
    b:array[0..35,0..35]of boolean;
    p,w,e:array[1..105000]of longint;
 function bfs(l1,l2,l3,l4:integer):longint;
 var i1,f,r,ux,uy:longint;
 begin
  fillchar(b,sizeof(b),true);
  f:=0;r:=1;b[l1,l2]:=false;
  p[r]:=l1;w[r]:=l2;e[r]:=0;
  repeat
   inc(f);
   if (p[r]=l3)and(w[f]=l4) then exit(e[f]);
   for i1:=1 to 4 do
    begin
     ux:=p[f]+dx[i1];uy:=w[f]+dy[i1];
     if (ux<=n)and(ux>=1)and(uy<=m)and(uy>=1)and(b[ux,uy])and(a[ux,uy]=1) then
      begin
       inc(r);
       b[ux,uy]:=false;
       p[r]:=ux;
       w[r]:=uy;
       e[r]:=e[f]+1;
      end;
    end;
  until f=r;
  bfs:=0;
 end;
begin
 assign(input,'puzzle.in');
 reset(input);
 read(n,m,q);
 for i:=1 to n do
  for j:=1 to m do
   read(a[i,j]);
 assign(output,'puzzle.out');
 rewrite(output);
 for i:=1 to q do
  begin
   min:=maxlongint;
   read(x1,y1,x2,y2,x3,y3);
   ans:=bfs(x1,y1,x2,y2);
   ans1:=bfs(x2,y2,x3,y3);
   ans2:=bfs(x1,y1,x3,y3);
   if (ans<>0)and(ans1<>0) then if min>ans+ans1 then min:=ans+ans1;
   if (ans1<>0)and(ans2<>0) then if min>ans1+ans2 then min:=ans1+ans2;
   if min=maxlongint then writeln('-1') else writeln(min);
  end;
 close(input);
 close(output);
end.
