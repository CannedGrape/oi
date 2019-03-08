program xxx;
var tr,h,a,c:array [1..100000] of longint;
 best,xx,o,x0,x,i,j,k,n,m:longint;
 min:real;
 minh,maxh:longint;
 fu,fd:longint; now,p:longint;
 next:array [1..100000,1..2]of longint;
 ans:array [1..2] of longint;
procedure qsort(x,y:longint);
var i,j:longint; k:longint;
begin
 i:=x; j:=y; k:=a[(i+j) div 2];
 while i<j do
  begin
   while a[i]<k do inc(i);
   while k<a[j] do dec(j);
   if i<=j then
    begin
     o:=a[i]; a[i]:=a[j]; a[j]:=o;
     o:=c[i]; c[i]:=c[j]; c[j]:=o;
     inc(i); dec(j);
    end;
  end;
 if x<j then qsort(x,j);
 if i<y then qsort(i,y);
end;
function place(x:longint):longint;
var i,j,k:longint;
begin
   i:=1; j:=n;
   while i<j do
    begin
     k:=(i+j) div 2;
     if a[k]>x then j:=k else i:=k+1;
    end;
   place:=i;
end;
function lowbit(x:longint):longint;
begin
 lowbit:=x and (-x);
end;
function find(x:longint):longint;
var i,j:longint;
begin
 find:=0;
 while x>0 do
  begin
   find:=find+tr[x];
   x:=x-lowbit(x);
  end;
end;
function f(pl,sum:longint):longint;
var i,j:longint;
begin
 i:=minh; j:=maxh+1;
 while i<j do
  begin
   k:=(i+j) div 2;
   if find(k)>sum then j:=k else i:=k+1;
  end;
 x:=c[k];

end;
begin
 read(n);
 minh:=100000000;
 maxh:=-100000000;
 for i:=1 to n do
 begin
  read(h[i]);
  a[i]:=h[i]; c[i]:=i;
  if h[i]>maxh then maxh:=h[i];
  if h[i]<minh then minh:=h[i];
 end;
 qsort(1,n);
 read(x0);
 for i:=n downto 1 do
  begin
   x:=place(h[i]);
   xx:=find(x);
   if xx<>0 then fd:=f(i,xx) else fd:=10000000;
   fu:=f(i,xx+1);
   if (h[fu]-a[i])<(h[fd]-a[i]) then
    next[i,1]:=fu else next[i,1]:=fd;
   if (fu-a[i])>=(fd-a[i]) then
    next[i,2]:=fu else next[i,2]:=fd;
   inc(tr[x]);
  end;
 min:=10000000;
 for i:=1 to n do
  begin
   now:=i; p:=1; ans[1]:=0; ans[2]:=0;
   while next[now,p]<>0 do
    begin
     if ans[1]+ans[2]+abs(h[now]-h[next[now,p]])>x0 then break;
     ans[p]:=ans[p]+abs(h[now]-h[next[now,p]]);
     now:=next[now,p]; p:=p mod 2+1;
    end;
   if ans[1]/ans[2]<min then begin min:=ans[1]/ans[2]; best:=i; end;
  end;
end.
