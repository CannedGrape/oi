program truck;
 var n,m,i,x,y,z,f1,f2,ans,max,min,l,r,mid,px:longint;
     d:array[1..1000] of longint;
     a:array[1..1000,1..10000,1..2] of longint;
     f:array[1..1000] of longint;
     b:array[1..1000,1..1000] of longint;
     p:array[1..1000] of boolean;
     pp:boolean;
function father(xx:longint):longint;
 begin
  if f[xx]<>xx then father:=father(f[xx])
  else father:=f[xx];
   f[xx]:=father;
 end;
procedure go(x:longint);
 var i:longint;
 begin
  if x=y then pp:=true;
  if pp then exit;
   for i:=1 to d[x] do
    if (p[a[x,i,1]]) and (a[x,i,2]>=mid) then
     begin
      p[a[x,i,1]]:=false;
       go(a[x,i,1]);
      p[a[x,i,1]]:=true;
     end;
 end;
 begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
   fillchar(b,sizeof(b),128);
   fillchar(a,sizeof(a),0);fillchar(d,sizeof(d),0);
   max:=0;min:=maxlongint;
    readln(n,m);
      for i:=1 to n do f[i]:=i;
    for i:=1 to m do
     begin
      readln(x,y,z);
       inc(d[x]);a[x,d[x],1]:=y;a[x,d[x],2]:=z;
       inc(d[y]);a[y,d[y],1]:=x;a[y,d[y],2]:=z;
        if z>max then max:=z;if z<min then min:=z;
         f1:=father(x);f2:=father(y);
         if f1<>f2 then f[f2]:=f1;
     end;
  readln(px);
   for i:=1 to px do
    begin
     readln(x,y);
      f1:=father(x);f2:=father(y);
      if f1<>f2 then writeln(-1)
      else if b[x,y]>=0 then writeln(b[x,y])
       else
        begin
         l:=min;r:=max;
          while l<=r do
           begin
            fillchar(p,sizeof(p),true);p[x]:=false;
            mid:=(l+r) div 2;
             pp:=false;
             go(x);
              if pp then begin
               ans:=mid;l:=mid+1;
                         end
              else r:=mid-1;
           end;
         writeln(ans);
          b[x,y]:=ans;b[y,x]:=ans;
        end;
    end;
  close(input);close(output);
 end.
