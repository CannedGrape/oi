uses math;
var  i,j,n,z,x,c:longint;
     ans:int64;
     a,s,d,f,o,p:array[0..100000] of longint;

procedure sqa(q,w:longint);
 var e,r,t,y:longint;
   begin
   e:=q;
   r:=w;
   t:=a[(e+r) div 2];
   repeat
   while a[e]<t do inc(e);
   while a[r]>t do dec(r);
   if e<=r then begin y:=a[e];a[e]:=a[r];a[r]:=y;
                      y:=d[e];d[e]:=d[r];d[r]:=y;
                      inc(e);dec(r);end;
   until e>r;
   if e<w then sqa(e,w);
   if r>q then sqa(q,r);
   end;

 procedure sqs(q,w:longint);
 var e,r,t,y:longint;
   begin
   e:=q;
   r:=w;
   t:=s[(e+r) div 2];
   repeat
   while s[e]<t do inc(e);
   while s[r]>t do dec(r);
   if e<=r then begin y:=s[e];s[e]:=s[r];s[r]:=y;
                      y:=f[e];f[e]:=f[r];f[r]:=y;
                      inc(e);dec(r);end;
  until r<e;
  if e<w then sqs(e,w);
   if r>q then sqs(q,r);
   end;

 procedure dow;
  var e,r,t,y:longint;
   begin
   e:=p[z];
   for r:=z downto i+1 do
    p[r]:=p[r-1];
   p[i]:=e end;

 procedure upw;
  var e,r,t,y:longint;
   begin
   e:=p[z];
   for r:=z to i-1 do
    p[r]:=p[r+1];
   p[i]:=e end;


 begin
 assign(input,'match.in');reset(input);
 assign(output,'match.out');rewrite(output);
 read(n);
 for i:=1 to n do begin read(a[i]);d[i]:=i;end;
 for i:=1 to n do begin read(s[i]);f[i]:=i;end;
 sqa(1,n);
 for i:=1 to n do o[d[i]]:=i;
 sqs(1,n);
 for i:=1 to n do p[f[i]]:=i;

 for i:=1 to n do if o[i]<>p[i] then begin
 for j:=1 to n do if o[i]=p[j] then begin z:=j;break;end;
 inc(ans,abs(i-z));
 ans:=ans mod 99999997;
 if z>i then dow else upw; end;
 write(ans);
close(input);
close(output);
 end.








