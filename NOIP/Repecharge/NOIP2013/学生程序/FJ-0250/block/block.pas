program block;
var
  i,j,n,y,min,t,k:longint;
  a:array [1..10000] of longint;

function  jia(x:longint):longint;
 begin
   for i:=1 to x do
       if a[i]>0  then
         begin
           y:=1;
           exit(y);
         end;
  end;
   begin
     assign(input,'block.in');
     reset(input);
     assign(output,'block.out');
     rewrite(output);
     min:=maxlongint;
     read(n);
     for i:=1 to n do
     read(a[i]);
     jia(n);
    for i:=1 to n do
    if (a[i]<min) and (a[i]<>0) then
       min:=a[i];
     for i:=1 to min do
       for j:=1 to n do
        dec(a[j]);
        inc(t,min);
        while y=1 do
       begin
       for i:=2 to n-1 do
       if (a[i]=0)  then
        inc(k);
        for i:=2 to n-1 do
         if (a[i]=0) and (a[i+1]=0) then
         dec(k);
        for i:=1 to n do
         if a[i]>0 then
        dec(a[i])
        else a[i]:=0;
        t:=t+k;
            y:=0;
           jia(n);
      end;
       write(t);
       close(input);close(output);
     end.




