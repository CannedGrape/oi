program truck;
 var n,m,q,i,j,ti:longint;
     a:array[0..50000,0..2]of longint;
     b:array[0..30000,0..2]of longint;
     z:array[0..50000]of longint;
     qz,qzz:array[0..30000]of longint;

begin
 assign(input,'truck.in');
 assign(output,'truck.out');
 reset(input);
 reset(output);

  readln(n,m);
  for i:=1 to m do
      readln(a[i,1],a[i,2],z[i]);
  readln(q);
  for i:=1 to q do
      readln(b[i,1],b[i,2]);

  for i:=1 to m do
      if a[i,1]>a[i,2] then
       begin
         ti:=a[i,1];
         a[i,1]:=a[i,2];
         a[i,2]:=ti;
       end;
  for i:=1 to q do
      if b[i,1]>b[i,2] then
       begin
         ti:=b[i,1];
         b[i,1]:=b[i,2];
         b[i,2]:=b[i,1];
       end;

  for i:=1 to q do
   begin
      if (a[i,1]=b[i,1]) and (a[i,2]=b[i,2])
         then qz[i]:=z[i]
              else qz[i]:=0-1;

      if a[i,1]=b[i,1] then
      begin
       j:=i;
       repeat
         repeat
           inc(j)
         until a[j,1]=b[i,2];
        if qz[j]>qz[i] then qz[i]:=qz[j];
       until a[j,1]+1=b[j,1];
      end;
   end;

  for i:=1 to q do
      writeln(qz[i]);


 close(input);
 close(output);
end.
