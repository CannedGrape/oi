program truck;
var n,m,q,st,en,i,ii,lf,rf,gr:longint;
    l,r,f,a,g,ff,u:array[-1..50010] of longint;
procedure sort(l1,r1: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l1;
         j:=r1;
         x:=a[(l1+r1) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=l[i];l[i]:=l[j];l[j]:=y;
                y:=r[i];r[i]:=r[j];r[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l1<j then
           sort(l1,j);
         if i<r1 then
           sort(i,r1);
      end;
function find(x:longint):longint;
begin
    if g[x]=x then exit(x);exit(find(g[x]));
end;
begin
    assign(input,'truck.in');reset(input);
    assign(output,'truck.out');rewrite(output);
    readln(n,m);
    for i:=1 to n do
     g[i]:=i;
    for i:=1 to m do
    begin
     readln(l[i],r[i],a[i]);
     if (f[l[i]]=0)and(f[r[i]]=0) then begin
      f[l[i]]:=l[i];f[r[i]]:=l[i];end
     else if (f[l[i]]<>0)and(f[r[i]]<>f[l[i]]) then f[r[i]]:=f[l[i]]
     else if (f[r[i]]<>0)and(f[r[i]]<>f[l[i]]) then f[l[i]]:=f[r[i]];
     for ii:=1 to gr do
      if ff[ii]=f[l[i]] then break;
     if ff[ii]<> f[l[i]] then begin
      inc(gr);ff[gr]:=f[l[i]];end;
    end;
    sort(1,m);
    for ii:=1 to gr do


     for i:=m downto 1 do
     if ff[ii]=f[l[i]] then
     begin
      lf:=find(l[i]);rf:=find(r[i]);
      if (lf<>rf) then begin
       g[lf]:=rf;if u[l[i]]=0 then u[l[i]]:=a[i];if u[r[i]]=0 then u[r[i]]:=a[i];
      end;
     end;



    readln(q);
    for ii:=1 to q do
    begin
     read(st,en);
     if f[st]<>f[en] then writeln(-1)
     else if u[st]>u[en] then writeln(u[en]) else writeln(u[st]);
    end;
    close(input);close(output);

end.
