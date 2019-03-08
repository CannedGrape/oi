var i,j,ans,n,first1,first2,first3,first4,last3,last4,last1,last2,s1,s2,s3,s4,t1,t2,t3,t4:longint;
    f1,f2,f3,f4:array[1..100000] of longint;
    h,g:array[1..100000] of longint;
function max(a,b,c,d,e:longint):longint;
 begin
   max:=a;
   if b>max then max:=b;
   if c>max then max:=c;
   if d>max then max:=d;
   if e>max then max:=e;
 end;
function min(a,b:longint):longint;
 begin
   if a<b then exit(a)
   else exit(b);
 end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
   begin
     read(h[i]);
     g[n-i+1]:=h[i];
   end;

  f1[1]:=1;last1:=1;s1:=1;
  f2[1]:=1;last2:=1;s2:=1;
  first1:=0;first2:=0;

  f3[1]:=1;last3:=1;s3:=1;
  f4[1]:=1;last4:=1;s4:=1;
  first3:=0;first4:=0;

  ans:=0;
  for i:=2 to n do
   begin
     t1:=0;t2:=0;
     if (s1+1) mod 2=0 then
      begin
        if h[i]>h[last1] then t1:=f1[i-1]+1;
      end
     else
      if h[i]<h[last1] then t1:=f1[i-1]+1;
     if f1[i-1]>t1 then f1[i]:=f1[i-1]
     else
      begin
        if first1=0 then first1:=i;
        f1[i]:=t1;
        last1:=i;
        inc(s1);
      end;
     if (s2+1) mod 2=0 then
      begin
        if h[i]<h[last2] then t2:=f2[i-1]+1;
      end
     else
      if h[i]>h[last2] then t2:=f2[i-1]+1;
     if f2[i-1]>t2 then f2[i]:=f2[i-1]
     else
      begin
        if first2=0 then first2:=i;
        f2[i]:=t2;
        last2:=i;
        inc(s2);
      end;

     t3:=0;t4:=0;
     if (s3+1) mod 2=0 then
      begin
        if g[i]>g[last3] then t3:=f3[i-1]+1;
      end
     else
      if g[i]<g[last1] then t3:=f3[i-1]+1;
     if f3[i-1]>t3 then f3[i]:=f3[i-1]
     else
      begin
        if first3=0 then first3:=i;
        f3[i]:=t3;
        last3:=i;
        inc(s3);
      end;

     if (s4+1) mod 2=0 then
      begin
        if g[i]<g[last4] then t4:=f4[i-1]+1;
      end
     else
      if g[i]>g[last4] then t4:=f4[i-1]+1;
     if f4[i-1]>t4 then f4[i]:=f4[i-1]
     else
      begin
        if first4=0 then first4:=i;
        f4[i]:=t4;
        last4:=i;
        inc(s4);
      end;
   end;
  ans:=0;
  ans:=max(f1[n],f2[n],f3[n],f4[n],ans);
  for j:=2 to min(60000000 div n,max(0,first1,first2,first3,first4)) do
   begin
     f1[j]:=1;last1:=j;s1:=1;
     f2[j]:=1;last2:=j;s2:=1;
     f3[j]:=1;last3:=j;s3:=1;
     f4[j]:=1;last4:=j;s4:=1;
     for i:=j+1 to n do
      begin
        t1:=0;t2:=0;
        if (s1+1) mod 2=0 then
         begin
           if h[i]>h[last1] then t1:=f1[i-1]+1;
         end
        else
         if h[i]<h[last1] then t1:=f1[i-1]+1;
        if f1[i-1]>t1 then f1[i]:=f1[i-1]
        else
         begin
           f1[i]:=t1;
           last1:=i;
           inc(s1);
         end;
        if (s2+1) mod 2=0 then
         begin
           if h[i]<h[last2] then t2:=f2[i-1]+1;
         end
        else
         if h[i]>h[last2] then t2:=f2[i-1]+1;
        if f2[i-1]>t2 then f2[i]:=f2[i-1]
        else
         begin
           f2[i]:=t2;
           last2:=i;
           inc(s2);
         end;

        t3:=0;t4:=0;
        if (s3+1) mod 2=0 then
         begin
           if g[i]>g[last3] then t3:=f3[i-1]+1;
         end
        else
         if g[i]<g[last1] then t3:=f3[i-1]+1;
        if f3[i-1]>t3 then f3[i]:=f3[i-1]
        else
         begin
           f3[i]:=t3;
           last3:=i;
           inc(s3);
         end;
       if (s4+1) mod 2=0 then
        begin
          if g[i]<g[last4] then t4:=f4[i-1]+1;
        end
       else
        if g[i]>g[last4] then t4:=f4[i-1]+1;
       if f4[i-1]>t4 then f4[i]:=f4[i-1]
       else
        begin
          f4[i]:=t4;
          last4:=i;
          inc(s4);
        end;
      end;
     ans:=max(f1[n],f2[n],f3[n],f4[n],ans);
   end;
  writeln(ans);
  close(input);close(output);
end.

