Program mxpiii;
Const
   moder=99999997;
Var
   a,b,c,q:array[0..200000] of longint;
   n,i,j,p,ans,t:longint;
   used,vis:array[0..200000] of boolean;
   flag:boolean;

Procedure qsort(l,r:longint);
Var
   i,j,mid,p:longint;
Begin
   i:=l; j:=r;
   mid:=a[(l+r) div 2];
   repeat
      while a[i]<mid do inc(i);
      while a[j]>mid do dec(j);
      if i<=j then
        begin
          p:=a[i]; a[i]:=a[j]; a[j]:=p;
          p:=b[i]; b[i]:=b[j]; b[j]:=p;
          p:=c[i]; c[i]:=c[j]; c[j]:=p;
          inc(i); dec(j);
        end;
   until i>j;
   if l<j then qsort(l,j);
   if i<r then qsort(i,r);
End;

Procedure change;
Begin
   for i:=1 to n do
     if q[i]<>i then
      begin
        ans:=(ans+abs(q[i]-i)) mod moder;
        if q[i]>i then
          begin
            for j:=i to q[i]-1 do
              begin
                t:=q[j]; q[j]:=q[j+1]; q[j+1]:=t;
              end;
          end
        else
            for j:=q[i] to i-1 do
              begin
                t:=q[j]; q[j]:=q[j+1]; q[j+1]:=t;
              end;
      end;
   for i:=1 to n do
     if q[i]<>i then begin flag:=false; exit; end;
   flag:=true;
End;

Begin
   assign(input,'match.in');
   assign(output,'match.out');
   reset(input);
   rewrite(output);
   readln(n);
   for i:=1 to n do
     begin
       read(a[i]);
       b[i]:=1;
       c[i]:=i;
     end;
   for i:=1 to n do
      begin
        read(a[i+n]);
        b[i+n]:=2;
        c[i+n]:=i;
      end;
   qsort(1,2*n);
   fillchar(used,sizeof(used),0);
   for i:=1 to 2*n do
     if not used[i] then
       begin
         p:=b[i];
         if p=1 then
           begin
             j:=i+1; while b[j]<>2 do inc(j);
             used[j]:=true; q[c[i]]:=c[j];
           end;
         if p=2 then
           begin
             j:=i+1; while b[j]<>1 do inc(j);
             used[j]:=true; q[c[j]]:=c[i];
           end;
         used[i]:=true;
       end;
   ans:=0;
   fillchar(vis,sizeof(vis),0);
   flag:=true;
   for i:=1 to n do if q[i]<>i then begin flag:=false; break; end;
   while not flag do change;
     {
       if not vis[i] then
         begin
            p:=q[i]; vis[i]:=false;
            while p<>i do
              begin
                vis[p]:=true;
                p:=q[p];
                ans:=(ans+1) mod moder;
              end;
         end;       }
   writeln(ans);
   close(input);
   close(output);
End.
