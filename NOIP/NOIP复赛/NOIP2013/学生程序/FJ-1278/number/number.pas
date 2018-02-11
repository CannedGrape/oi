program number;
 var a:array[1..1000000] of longint;
     b:array[1..1000000] of longint;
     c:array[1..1000000] of longint;
     i,j,p,n,max:longint;
 begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  read(n,p);
  for i:=1 to n do read(a[i]);
  max:=-1000000000;
  for i:=1 to n do
   begin
    for j:=1 to i do
    begin
      b[i]:=b[i]+a[j];
      if b[i]>max then max:=b[i];
    end;
    b[i]:=max;
    max:=-1000000000;
   end;

   for i:=1 to n do
   begin
     if i=1 then c[i]:=b[i] else
   begin
    for j:=1 to i-1 do
     begin
      begin
       c[i]:=b[j]+c[j];
       if c[i]>max then max:=c[i];
      end;
      c[i]:=max;
     end;
      max:=-1000000000;
   end;
  end;
   for i:=1 to n do if (c[i]>max) and (c[i]<p) then max:=c[i];
   write(max);
   close(input);close(output);
  end.


