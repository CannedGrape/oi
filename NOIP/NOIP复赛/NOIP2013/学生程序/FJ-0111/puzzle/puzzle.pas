var
  a:array[1..100,1..100]of longint;
  t:array[1..1000]of longint;
  n,m,q,i,j,u,v,w,x,y,z:longint;
procedure s(u,v,y,z,h:longint);
var p:longint;
begin
    if a[y,z]=2 then begin if (a[y-1,z]=3)or (a[y+1,z]=3)or(a[y,z-1]=3)or(a[y,z+1]=3) then inc(t[h])
  else t[h]:=-1; end
   else
    begin
    if a[u-1,v]<>0 then  begin p:=a[u,v];a[u,v]:=a[u-1,v];a[u-1,v]:=p; inc(t[h]); s(u,v,y,z,h);end
    else if a[u+1,v]<>0 then  begin p:=a[u,v];a[u,v]:=a[u+1,v];a[u+1,v]:=p; inc(t[h]); s(u,v,y,z,h); end
      else if a[u,v-1]<>0 then  begin p:=a[u,v];a[u,v]:=a[u,v-1];a[u,v-1]:=p;  inc(t[h]); s(u,v,y,z,h); end
        else if a[u,v+1]<>0 then  begin p:=a[u,v];a[u,v]:=a[u,v+1];a[u,v+1]:=p; inc(t[h]);  s(u,v,y,z,h);end
    end;
end;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q); fillchar(a,sizeof(a),0);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  readln;
  for i:=1 to q do
    begin
      read(u,v,w,x,y,z);
      a[u,v]:=2;
      a[w,x]:=3;
      a[y,z]:=4;
      s(u,v,y,z,i);
    end;
  readln;
  for i:=1 to q do
    writeln(t[i]);
  close(input);close(output);
end.