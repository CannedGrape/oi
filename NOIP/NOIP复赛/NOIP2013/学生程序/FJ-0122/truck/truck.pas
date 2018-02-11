var
   first,next,endl,w:array[0..600000]of longint;
   b,bb:array[0..6000000]of boolean;
   n,m,i,j,k,x,y,min,tot,t,z,q:longint;
procedure setl(x,y,z:longint);
begin
   inc(tot);
   next[tot]:=first[x];
   first[x]:=tot;
   endl[tot]:=y;
   w[tot]:=z;
   inc(tot);
   next[tot]:=first[y];
   first[y]:=tot;
   endl[tot]:=x;
   w[tot]:=z;
end;
procedure dfs(k,ma:longint);
var
   i,j:longint;
begin
   if t>m then exit;
   if k=y then
   begin
     if ma>min then min:=ma;
     exit;
   end;
   j:=first[k];
   while j<>0 do
   begin
     if not b[endl[j]] then
     begin
       b[endl[j]]:=true;
       inc(t);
       if w[j]<ma then dfs(endl[j],w[j])
         else dfs(endl[j],ma);
       b[endl[j]]:=false;
     end;
     j:=next[j];
   end;
end;

begin
   assign(input,'truck.in');reset(input);
   assign(output,'truck.out');rewrite(output);
   readln(n,m);
   for i:=1 to m do
   begin
     readln(x,y,z);
     setl(x,y,z);
     bb[x]:=true;bb[y]:=true;
   end;
   readln(q);
   for i:=1 to q do
   begin
     t:=0;
     min:=-maxlongint;
     for j:=1 to n do b[j]:=false;
     readln(x,y);
     if (not bb[x])or(not bb[y]) then
     begin
       writeln(-1);
       continue;
     end;
     dfs(x,200000);
    writeln(min);
   end;
   readln;
   close(input);close(output);
end.
