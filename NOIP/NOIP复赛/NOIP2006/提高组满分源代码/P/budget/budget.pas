const inf                       ='budget.in';
      ouf                       ='budget.out';
      maxn                      =32000;
      maxg                      =1000;
      maxmg                     =60;

var   n,i,tg,j,tmg,m            :longint;
      pr                        :array[1..maxg]of longint;
      s                         :array[1..maxg]of longint;
      last,bl                   :array[1..maxmg]of longint;
      pre                       :array[1..maxg]of longint;
      f                         :array[boolean,0..maxn]of longint;

procedure init;
 var    d               :array[1..60]of longint;
        v,p,q           :array[1..60]of longint;
        ps              :array[1..60]of longint;
 begin
   assign(input,inf);
   reset(input);
   readln(n,m);
   tg:=0;
   for i:=1 to m do
     begin
       readln(v[i],p[i],q[i]);
       if q[i]=0 then
        begin
          inc(tg); pr[tg]:=v[i]; s[tg]:=pr[tg]*p[i];
          last[tg]:=tg; bl[tg]:=tg;
          ps[i]:=tg;
        end;
     end;
   tmg:=tg;
   for i:=1 to m do
     if q[i]>0 then
     begin
       j:=ps[q[i]];
       bl[j]:=last[j];
       while bl[j]<>0 do
       begin
         inc(tg); pr[tg]:=pr[bl[j]]+v[i];
         pre[tg]:=last[j]; last[j]:=tg;
         s[tg]:=s[bl[j]]+v[i]*p[i];
         bl[j]:=pre[bl[j]];
       end;
     end;
   close(input);
 end;

procedure cal;
 var max,ans,price,tmax         :longint;
     now,las                    :boolean;
 begin
   ans:=0; max:=0;
   i:=0;
   now:=true; las:=false;
   fillchar(f,sizeof(f),0);

   f[now,0]:=1;

   repeat
     now:=not now; las:=not las;
     fillchar(f[now],sizeof(f[now]),0);
     inc(i);
     bl[i]:=last[i];
     tmax:=max;
     while bl[i]<>0 do
     begin
       j:=bl[i];
       for price:=max downto 0 do
         if f[las,price]>0 then
         if price+pr[j]<=n then
         begin
           if f[las,price]+s[j]>f[now,price+pr[j]] then f[now,price+pr[j]]:=f[las,price]+s[j];
           if price+pr[j]>tmax then tmax:=price+pr[j];
           if f[now,price+pr[j]]>ans then ans:=f[now,price+pr[j]];
         end;
       bl[i]:=pre[bl[i]];
     end;
     for j:=max downto 0 do
       if f[las,j]>f[now,j] then f[now,j]:=f[las,j];
     max:=tmax;
   until i=tmg;
   assign(output,ouf);
   rewrite(output);
   writeln(ans-1);
   close(output);
 end;

begin
  init; cal;
end.
