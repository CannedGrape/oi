var a,s,d:array[0..100001] of longint;
    f:array[0..501,0..200] of boolean;
    b:array[0..501] of boolean;
    n,i,j,m,k,o,p,x1,y1,ans:longint;

 procedure sa(q,w: longint);
      var e,r,t,y: longint;
      begin
         e:=q;
         r:=w;
         t:=a[(q+w) div 2];
         repeat
           while a[e]<t do inc(e);
           while t<a[r] do dec(r);
           if not(e>r) then
             begin
                y:=a[e];a[e]:=a[r];a[r]:=y;
                y:=s[e];s[e]:=s[r];s[r]:=y;
                inc(e);dec(r);
             end;
         until e>r;
         if q<r then
           sa(q,r);
         if e<w then
           sa(e,w);
      end;

 procedure sd(q,w: longint);
      var e,r,t,y: longint;
      begin
         e:=q;
         r:=w;
         t:=s[(q+w) div 2];
         repeat
           while s[e]<t do inc(e);
           while t<s[r] do dec(r);
           if not(e>r) then
             begin
                y:=a[e];a[e]:=a[r];a[r]:=y;
                y:=s[e];s[e]:=s[r];s[r]:=y;
                inc(e);dec(r);
             end;
         until e>r;
         if q<r then
           sd(q,r);
         if e<w then
           sd(e,w);
      end;

 procedure deal(q,w:longint);
 var bo:boolean;
     mid:longint;
     e,r,t,y,l:longint;

  begin
  mid:=0;
  for l:=q to w do if s[l]>mid then begin
   e:=s[l] div 200;
   r:=s[l] mod 200;

   for o:=r+1 to 199 do
           if f[e,o] then begin  bo:=true;
                          mid:=e*200+o;
                          inc(ans);
                          break;end;
   if not bo then begin
     for k:=e+1 to x1 do
      if b[k] then for o:=0 to 199 do
       if f[k,o] then begin mid:=k*200+o;
                            inc(ans);
                            break;end;
       break;end;end;
   for l:=q to w do begin  f[s[l] div 200,s[l] mod 200]:=true;
                           b[s[l] div 200]:=true;end;
  end;




 begin
 assign(input,'block.in');reset(input);
 assign(output,'block.out');rewrite(output);
 read(n);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do s[i]:=i;
 x1:=n div 200;
 y1:=n mod 200;
 sa(1,n);
 j:=1;
 for i:=1 to n do if a[i]<>a[j] then
                          begin sd(j,i-1);
                                j:=i;
                          end;
 sd(j,n);

 f[x1,y1+1]:=true;
 b[x1]:=true;
 j:=1;


 for i:=1 to n do if a[i]<>a[j] then begin
                                    deal(j,i-1);
                                    j:=i;
                                    end;
 deal(j,n);

write(ans);
close(input);
close(output);
 end.
