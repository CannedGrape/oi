program culture;
var n,kk,m,s,t,i,j,x,y,z,ans,max:longint;
    c:array[0..101]of longint;
    d:array[0..101,0..101]of longint;
    fc:array[0..101,0..101]of boolean;
    k,k1:array[0..101]of boolean;
procedure f(u:longint);
var i:longint;
    lzy:array[1..101]of boolean;
begin
 if u=t then begin
  if(max<ans)then
   ans:=max;
  exit;
 end;
 for i:=1 to kk do
    lzy[i]:=false;
 k[c[u]]:=true;//biao ji
 for i:=1 to kk do
  if (fc[c[u],i]=true)and(k1[i]=false) then
  begin
   k1[i]:=true;
   lzy[i]:=true;
  end;
 for i:=1 to n do
  if(d[u,i]>0)and(k[c[i]]=false)
  and(k1[c[i]]=false)then
  begin
   k[c[i]]:=true;max:=max+d[u,i];
   f(i);k[c[i]]:=false;
   max:=max-d[u,i];
  end;
 k[c[u]]:=false;//hui fu
 for i:=1 to kk do
  if (fc[c[u],i]=true)and(lzy[i]) then
   k1[i]:=false;
end;
begin
 assign(input,'culture.in');reset(input);
 assign(output,'culture.out');rewrite(output);
 readln(n,kk,m,s,t);
 for i:=1 to n do
  read(c[i]);
 if c[s]=c[t] then
 begin
  writeln('-1');halt;
 end;
 for i:=1 to n do
 for j:=1 to n do
 begin
  read(x);
  if x=1 then fc[j,i]:=true;
 end;
 for i:=1 to m do
 begin
  read(x,y,z);
  if (d[x,y]=0)or(z<d[x,y]) then
  begin
   d[x,y]:=z;
   d[y,x]:=z;
  end;
 end;
 ans:=maxlongint;
 f(s);
 if ans<maxlongint then writeln(ans)
 else writeln('-1');
 close(input);close(output);
end.
