program number;
  var a,b,c:array[1..1000000] of  int64;
      i,j,k,max,n,p,t:longint;
  procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=c[(l+r) div 2];
         repeat
           while c[i]<x do
            inc(i);
           while x<c[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
  begin
    assign(input,'number.in');
    reset(input);
    assign(output,'number.out');
    rewrite(output);
    readln(n,p);
    for i:=1 to n do read(a[i]);
    b[1]:=a[1];
    for i:=2 to n do
      begin
        max:=a[i];
        for j:=1 to i do
          begin
            t:=0;
            for k:=1 to j do begin
              if t+a[k]>max then max:=t+a[k];
              t:=t+a[k];
            end;
          end;
        b[i]:=max;
      end;
    c[1]:=b[1];
    for i:=2 to n do
     begin
       max:=c[1]+b[1];
       for j:=2 to i-1 do
         if c[j]+b[j]>max then max:=c[j]+b[j];
       c[i]:=max;
     end;
    sort(1,n);
    if c[n]<p then write(c[n]);
    close(input);
    close(output);
  end.





