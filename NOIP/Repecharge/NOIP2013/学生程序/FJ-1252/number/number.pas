program ex1;
  var n,x,i,j,k:longint;
      max:int64;
       a:array[1..1000000]of longint;
       b,d:array[1..1000000]of int64;
  function try(i,j:longint):longint;
  var k:longint;
      s:int64;
   begin
     s:=0;
     for k:=i to j do
       s:=(s+a[k]);
       try:=s;
   end;
   begin
    assign(input,'number.in'); reset(input);
    assign(output,'number.out'); rewrite(output);
     read(n,x);
      for i:=1 to n do
        read(a[i]);
     b[1]:=a[1];
     for i:=2 to n do
     begin
     max:=-maxlongint;
       for j:=1 to i do
         for k:=j to i do
           if try(j,k)>max then max:=try(j,k);
     b[i]:=max;
   end;
   d[1]:=b[1];
   for i:=2 to n do
     begin
       max:=-maxlongint; k:=0;
       for j:=1 to i-1 do
         if b[j]+d[j]>max then  max:=b[j]+d[j];
         d[i]:=max;
     end;
     max:=-maxlongint;
     for i:=1 to n do if max<d[i] then max:=d[i];
     writeln(max mod x);
     close(input); close(output);
     end.
