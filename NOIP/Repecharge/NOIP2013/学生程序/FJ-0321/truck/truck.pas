program fuck;
var
 a,b:array[0..1000,0..1000] of longint;
 fa:array[0..1000] of longint;
 f:array[0..1000] of boolean;      o:boolean;
 i,j,k,l,s,t,m,n,r,mid,p:longint;
function max(x,y:longint):longint;
begin
 if x>y then exit(x) else exit(y);
end;
function find(x:longint):longint;
begin
 find:=x;
 while fa[find]<>find do find:=fa[find];
 fa[x]:=find;
end;
procedure union(x,y:longint);
begin
 fa[find(x)]:=find(y);
end;
procedure search(x:longint);
var i:longint;
begin
 if x=k then begin o:=true; exit; end;
 if o=true then exit;
 if f[x]=false then exit;
 f[x]:=false;
 for i:=1 to b[x,0] do
  if a[x,b[x,i]]>=mid then
   search(b[x,i]);
end;
begin
 assign(input,'truck.in');
 assign(output,'truck.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to n do
  fa[i]:=i;
 for i:=1 to m do
  begin
  readln(j,k,l);
  inc(b[j,0]);
  b[j,b[j,0]]:=k;
  inc(b[k,0]);
  b[k,b[k,0]]:=j;
  union(j,k);
  a[j,k]:=l;
  a[k,j]:=l;
  s:=max(s,l);
  end;
 readln(p);
 for i:=1 to p do
  begin
  readln(j,k);
  if find(fa[j])<>(fa[k]) then begin writeln(-1); continue; end;
  l:=1; r:=s;
  while s-l>1 do
   begin
   fillchar(f,sizeof(f),1);
   o:=false;
   mid:=(l+r) div 2;
   search(j);
   if o= true then l:=mid else r:=mid;
   end;
  mid:=r;
  o:=false;
  search(j);
  if o=true then writeln(r) else writeln(l);
  end;
 close(input);
 close(output);
end.