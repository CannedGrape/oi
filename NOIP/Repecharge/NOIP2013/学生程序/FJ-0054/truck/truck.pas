var
   n,m,i,j,x,y,z,tot,q:longint;
   bo,f:array[0..1000] of boolean;
   first,next,en,a,d:array[0..100000] of longint;
   dis:array[0..1000] of longint;
procedure selt(x,y,s:longint);
begin
   inc(tot);
   next[tot]:=first[x];
   first[x]:=tot;
   en[tot]:=y;
   a[tot]:=z;
end;
procedure ss(qi:longint);
var k,u,t,w,xx,o:longint;
begin
   t:=0;w:=1;d[1]:=qi; bo[qi]:=false;
   fillchar(dis,sizeof(dis),$5f);
  repeat
       inc(t);
       xx:=d[t];
       bo[xx]:=false;
       k:=first[xx];
       while k<>0 do
         begin
           u:=en[k];
           o:=dis[xx];
           if dis[u]=dis[0] then
                 begin
                   if o>a[k] then dis[u]:=a[k]
                   else dis[u]:=o;
                    if not bo[u] then
                    begin
                     inc(w);
                      bo[u]:=true;
                     d[w]:=u;
                    end;
                end
                 else
                 begin
                    if (o>=a[k]) then o:=a[k];
                    if o>dis[u] then
                     begin
                      dis[u]:=o;
                      if not bo[u] then
                      begin
                        inc(w);
                        bo[u]:=true;
                        d[w]:=u;
                      end;
                     end;
                 end;
             k:=next[k];
         end;
  until t>w;
end;

begin
    assign(input,'truck.in');reset(input);
   assign(output,'truck.out');rewrite(output);
   readln(n,m);
   for i:=1 to m do
     begin
       readln(x,y,z);
       selt(x,y,z);
       selt(y,x,z);
     end;
     fillchar(bo,sizeof(bo),0);
   readln(q);
   for  i:=1 to q do
     begin
       readln(x,y);
       ss(x);
       if dis[y]=dis[0] then writeln(-1) else writeln(dis[y]);
     end;   close(input);close(output);
end.
