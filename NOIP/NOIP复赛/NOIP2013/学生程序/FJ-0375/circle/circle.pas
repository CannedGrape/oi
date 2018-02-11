 var i,n,m,y:longint;
    k,x,sum:int64;
    a:array[0..1000000] of longint;
 begin
    assign(input,'circle.in'); reset(input);
    assign(output,'circle.out'); rewrite(output);
    read(n,m,k,x);
    sum:=1;
    a[1]:=x;  i:=0;
   repeat
       if (a[i]<n-m) then a[i+1]:=a[i]+m else
       begin
       if (a[i]+m>n-1) then a[i+1]:=(a[i]+m) mod n;
       end;
       i:=i+1;
    until a[i]=a[1];

    repeat
      sum:=sum*10;
      until sum>=i;
    sum:=(sum mod i);

   for y:=1 to sum do
      begin
        if (x<n-m) then x:=x+m else
         begin
           if (x+m>n-1) then x:=(x+m) mod n;
           end;
        end;
      write(x);


     close(input); close(output);
     end.

