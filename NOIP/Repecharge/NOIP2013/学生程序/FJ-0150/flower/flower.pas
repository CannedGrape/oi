program flower;
var i,j,n,s:longint;
    a:array[0..100000]of longint;

 begin
   assign(input,'flower.in');
   reset(input);
   assign(output,'flower.out');
   rewrite(output);
   readln(n);
   a[0]:=0;a[n+1]:=0;
   for i:=1 to n do
     read(a[i]);
   readln;
   for i:=1 to n do
     if not (a[i]>a[i-1]) and not (a[i]>a[i+1]) or not (a[i]<a[i-1]) and not (a[i]<a[i+1])
       then
         for j:=i to n do
          a[j]:=a[j+1];
   s:=0;
   for i:=1 to n do
     if a[i]>0 then s:=s+1;
   writeln(s);
   readln;
   close(input);
   close(output);
end.
