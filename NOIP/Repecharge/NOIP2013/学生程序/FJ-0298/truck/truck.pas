var n,m,i,a,b,w,q,ans,x,y,l:longint;qq:boolean;
    map:array[0..2005,0..2005]of 0..1;
    pd,v:array[0..2005,0..2005]of longint;
    bo,lo:array[0..2005]of longint;
procedure  dfs(k:longint);
var i,j:longint;
begin
  if k=y then
        begin
          for j:=1 to l do
               if lo[j]<ans then begin qq:=true; ans:=lo[j];end;
          if (ans<>maxlongint) and (pd[x,y]<ans) then begin pd[y,x]:=ans;pd[x,y]:=ans;end;
          ans:=maxlongint;
          exit;
        end;
  for i:=1 to n do
    if (map[k,i]=1) and (bo[i]=0)and (i<>x) then
      begin
        inc(l);lo[l]:=v[k,i];bo[i]:=1;
        dfs(i);
        dec(l);bo[i]:=0;
      end;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  fillchar(map,sizeof(map),0);
  for i:=1 to m do
    begin
      readln(a,b,w);
      map[a,b]:=1;
      map[b,a]:=1;
      v[a,b]:=w;
      v[b,a]:=w;
    end;
  readln(q);
  fillchar(pd,sizeof(pd),0);
  for i:=1 to q do
    begin
      fillchar(bo,sizeof(bo),0);
      readln(x,y);l:=0; ans:=maxlongint;
      if (pd[x,y]<>0) then writeln(pd[x,y])
        else
          begin
            qq:=false;
            bo[x]:=1;ans:=maxlongint;
            dfs(x);
            if qq then writeln(pd[x,y])
              else writeln(-1);
          end;
    end;
  close(input);close(output);
end.
