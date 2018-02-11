var
   first,next,endl,w:array[0..200000]of longint;
   bo:array[1..1000]of boolean;
   i,j,k,m,n,x,y,z,tot,q,xx,yy,ans:longint;
procedure setl(x,y,z:longint);
begin
  inc(tot);
  next[tot]:=first[x];
  first[x]:=tot;
  endl[tot]:=y;
  w[tot]:=z;
end;
procedure dfs(x,y:longint);
var
  i,j,k,l:longint;
begin
  bo[x]:=false;
  if x=yy then if ans<y then ans:=y;
  k:=first[x];l:=endl[k];
  while k<>0 do
  begin
     if bo[l] then
     begin
      if y>w[k] then
      dfs(l,w[k]) else dfs(l,y);
      bo[l]:=true;
     end;
      k:=next[k];l:=endl[k];
  end;
end;
{function ef(l,r:longint):longint;
var
  i,j,k,mid:longint;
begin
   while l<r do
   begin
     mid:=(l+r) div 2;
     if check(mid) then l:=mid else r:=mid;
     if l:=r-1 then break;
   end;
   if check(r) then exit(r) else
     if check(l) then exit(l) else exit(-1);
end;}
begin
assign(input,'truck.in');reset(input);
assign(output,'truck.out');rewrite(output);
   readln(n,m);
   for i:=1 to m do
   begin
     readln(x,y,z);
     setl(x,y,z);
     setl(y,x,z);
   end;
   readln(q);
   for i:=1 to q do
   begin
     fillchar(bo,sizeof(bo),true);
     readln(xx,yy);
     ans:=-1;
     dfs(xx,maxlongint);
     writeln(ans);
   end;
close(input);close(output);
end.
