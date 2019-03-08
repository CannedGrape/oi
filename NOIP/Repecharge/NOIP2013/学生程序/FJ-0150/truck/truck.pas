program truck;
var a,d:array[1..10000,1..10000]of longint;
   i,j,b,m,n,x,y,z,max,min,q:longint;
begin
 assign(input,'truck.in');
 reset(input);
 assign(output,'truck.out');
 rewrite(output);
  read(n,m);
  readln;
  for i:=1 to n do
    for j:=1 to n do
      begin
       d[i,j]:=0;
       a[i,j]:=0;
      end;
  for i:=1 to m do
   begin
    read(x,y,z);
    d[x,y]:=z;
    d[y,x]:=z;
    readln;
   end;
   readln(q);
   for i:=1 to q do
    begin
     read(x,y);
     a[x,y]:=1;
     readln;
    end;
    for i:=1 to n do
      for j:=1 to n do
        if a[i,j]<>0 then
         begin
          min:=100000;
          x:=i;
          while x<>j do
           begin
            max:=0;
             for b:=x to j do
               if max<d[x,b] then
               begin
               max:=d[x,b];
               x:=b;
               end;
             if max<min then min:=max;
            if min=0 then begin writeln(-1);break; end;
            end;
          writeln(min);
       end;
      close(input);
      close(output);
end.




