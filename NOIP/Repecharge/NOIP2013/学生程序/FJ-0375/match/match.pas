type
    arr=array[1..100000] of int64;
var i,j,s,t,n,m,h,k:longint;
    a,b,c:arr;

procedure sort(l,r: longint);
var
    i,j,x,y,xx,yy: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         k:=k+1;
         repeat
           while a[i]<x do i:=i+1;
           while x<a[j] do j:=j-1;
           if not(i>j) then
             begin
                y:=a[i]; a[i]:=a[j]; a[j]:=y;
                i:=i+1;
                j:=j-1;

             end;
         until i>j;
         if l<j then sort(l,j);
         if i<r then sort(i,r);
      end;
begin
    assign(input,'match.in'); reset(input);
    assign(output,'match.out'); rewrite(output);
    read(n);
    k:=0;
    m:=0;
    for i:=1 to n do
      read(a[i]); sort(1,n);
    if m<k then m:=k;

    k:=0;
    for i:=1 to n do
      read(a[i]); sort(1,n);

    if m<k then m:=k;
    m:=(m-1) mod 99999997;
    write(m);
    close(input); close(output);
     end.
