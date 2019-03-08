program circle;
  var
    m,n,k,x,t,c,h,y:longint;
    a:array [0..10000000] of longint;
    procedure game;
    var
      i,j:longint;
      begin
      for c:=1 to y do
      begin
      for i:=0 to n-1 do
        if m+i<=n-1 then
         begin
         if a[m+i]>a[i] then
           a[m+i]:=a[m+i]-m
           else
             a[m+i]:=a[m+i]+n-m;
         end;
     for j:=0 to n-1 do
      if n-m+j>=n-1 then
    begin
  if a[j]<a[n-m+j] then
        a[j]:=a[j]+n-m
   else  a[j]:=a[j]-m;
    end;

     end;


      end;

  begin
     assign(input,'circle.in');
     reset(input);
     assign(output,'circle.out');
     rewrite(output);
      read(n,m,k,x);
      y:=1;
      for t:=0 to n-1 do
       a[t]:=t;
      for t:=1 to k do
     y:=y*10;
     game;
     for t:=0 to n-1 do
       if x=a[t] then
        write(t);
     close(input);close(output);
   end.


