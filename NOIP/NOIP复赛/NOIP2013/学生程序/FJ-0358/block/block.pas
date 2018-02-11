var n,i,q:longint;
    a,h:array[1..100000] of longint;

  procedure qsort(b,c:longint);
   var l,k,m,t,p:longint;
 begin
    l:=b;
    k:=c;
    p:=(l+k) div 2;
    m:=a[p];
   repeat
     while a[l]<m do inc(l);
     while a[k]>m do dec(k);
    if k>l then
     begin
      t:=a[l];a[l]:=a[k];a[k]:=t;inc(l);dec(k);
     end;
   until k<l;
    if k>b then qsort(b,k);
    if l<c then qsort(l,c);
 end;

   procedure pai(x,y:longint);
    var s,t,l1,l2,j,u:longint;
   begin
     if x=y then exit;
     l1:=x;l2:=y;
      qsort(x,y);
       s:=a[1];q:=q+a[1];
        for j:=l1 to l2 do begin
         h[j]:=h[j]-s;  a[j]:=h[j]; end;
        t:=1;
        u:=l1;

    repeat
     while a[t]<1 do inc(t);
      pai(u,t);
      u:=t;
     until t>l2


   end;

   begin
    readln(n);
   for i:=1 to n do
    begin
     read(a[i]);
     h[i]:=a[i];
    end;
    q:=0;
    pai(1,n);

    write(q);









 end.

