program rainfall;
type
seg             = record
                     start,en   : double;
                     pos        : double;
                     tv         : double;
                     end;
var
n,w,t,v         : longint;
b               : array[1..12,1..3] of longint;
s               : array[1..22,1..1000] of seg;
ns              : array[1..22] of longint;
inter           : array[1..50000] of double;
ninter          : longint;
i,j             : longint;
ans             : double;
oa,na           : double;
procedure genseg(id: longint; lr: longint);
   var
   store        : longint;
   nt,nextt     : double;
   lp,rp        : double;
   neg          : boolean;
   np           : double;
   begin
   store:= id*2-2+lr;
   if b[id,3]=0 then begin
      ns[store]:= 1;
      with s[store,1] do begin
         start:= 0; en:= t;
         pos:= b[i,1]+(lr-1)*b[i,2];
         tv:= 0;
         end;
      end
   else begin
      nt:= 0; lp:= 0+(lr-1)*b[i,2]; rp:= w-b[i,2]+(lr-1)*b[i,2];
      if b[i,3]>0 then neg:= false else neg:= true;
      np:= b[i,1]+(lr-1)*b[i,2];
      ns[store]:= 0;
      while nt<t-1e-7 do begin
         if neg then begin
            nextt:= (np-lp)/abs(b[i,3])+nt;
            if nextt>t then nextt:= t;
            inc(ns[store]);
            with s[store,ns[store]] do begin
               start:= nt; en:= nextt;
               pos:= np+abs(b[i,3])*nt;
               tv:= -abs(b[i,3]);
               end;
            neg:= false;
            np:= lp;
            nt:= nextt;
            end
         else begin
            nextt:= (rp-np)/abs(b[i,3])+nt;
            if nextt>t then nextt:= t;
            inc(ns[store]);
            with s[store,ns[store]] do begin
               start:= nt; en:= nextt;
               pos:= np-abs(b[i,3])*nt;
               tv:= abs(b[i,3]);
               end;
            neg:= true;
            np:= rp;
            nt:= nextt;
            end;
         inc(ninter); inter[ninter]:= nt;
         end;
      end;
   end;
procedure calcinter(id1,id2: longint);
   var
   i            : longint;
   p            : longint;
   a,b,tm       : double;
   begin
   p:= 1;
   for i:= 1 to ns[id1] do begin
      while (p<=ns[id2])and(s[id2,p].start<s[id1,i].en) do begin
         a:= s[id1,i].pos-s[id2,p].pos;
         b:= s[id2,p].tv-s[id1,i].tv;
         if abs(b)<1e-7 then begin
            inc(p);continue;
            end
         else begin
            tm:= a/b;
            if (tm>s[id1,i].start)and(tm>s[id2,p].start)
            and(tm<s[id1,i].en)and(tm<s[id2,p].en) then begin
               inc(ninter); inter[ninter]:= tm;
               end;
            end;
         inc(p);
         end;
      if p>1 then dec(p);
      end;
   if ninter>10000 then exit;
   end;
procedure sortinter;
   procedure sort(l,r: longint);
      var
      i,j       : longint;
      m,t       : double;
      begin
      m:= inter[(l+r) shr 1];
      i:= l; j:= r;
      repeat
         while inter[i]<m-1e-7 do inc(i);
         while inter[j]>m+1e-7 do dec(j);
         if (i<=j) then begin
            t:= inter[i]; inter[i]:= inter[j]; inter[j]:= t;
            inc(i); dec(j);
            end;
      until i>j;
      if i<r then sort(i,r);
      if l<j then sort(l,j);
      end;
   var
   p            : longint;
   i            : longint;
   begin
   if ninter>1 then sort(1,ninter);
   p:= 1;
   for i:= 2 to ninter do begin
      if inter[i]-inter[i-1]>1e-7 then begin
         inc(p);
         inter[p]:= inter[i];
         end;
      end;
   ninter:= p;
   end;
function getarea(t: double): double;
   var
   a    : array[1..20] of double;
   lr   : array[1..20] of longint;
   tm   : double;
   area : double;
   i,j,p: longint;
   begin
   for i:= 1 to n shl 1 do begin
      if odd(i) then lr[i]:= 1 else lr[i]:= -1;
      p:= 1;
      while s[i,p].en<t-1e-6 do inc(p);
      a[i]:= s[i,p].pos+s[i,p].tv*t;
      end;
   for i:= 1 to n shl 1 do
      for j:= i+1 to n shl 1 do
         if a[i]>a[j] then begin
            tm:= a[i]; a[i]:= a[j]; a[j]:= tm;
            p:= lr[i]; lr[i]:= lr[j]; lr[j]:= p;
            end;
   p:= 0; area:= 0;
   for i:= 1 to n shl 1 do begin
      if p>0 then area:= area+a[i]-a[i-1];
      p:= p+lr[i];
      end;
   getarea:= w-area;
   end;
begin
assign(input,'rainfall.in'); reset(input);
read(n,w,t,v);
for i:= 1 to n do begin
   read(b[i,1],b[i,2],b[i,3]);
   if b[i,2]=w then b[i,3]:= 0;
   end;
ninter:= 2; inter[1]:= 0; inter[2]:= t;
for i:= 1 to n do begin
   genseg(i,1); genseg(i,2);
   end;
for i:= 1 to n shl 1 do begin
   j:= i;
   for j:= i+1 to n shl 1 do
      calcinter(i,j);
   end;
sortinter;
ans:= 0;
oa:= 0; na:= getarea(inter[1]);
for i:= 2 to ninter do begin
   oa:= na;
   na:= getarea(inter[i]);
   ans:= ans+(oa+na)/2*(inter[i]-inter[i-1]);
   end;
assign(output,'rainfall.out'); rewrite(output);
if ans<0 then ans:= 0;
writeln(ans*v:0:2);
close(output);
end.
