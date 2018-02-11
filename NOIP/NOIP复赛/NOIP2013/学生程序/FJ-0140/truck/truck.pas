 program truck;
 var
   n,m,x,y,z,q,i,j,v:longint;
   way:array[1..1000,1..1000] of longint;
   long:array[1..30000] of longint;
 procedure find(l,r:longint);
 var
   i,j,k:longint;
 begin
   for i:=1 to n do
     if (way[l,i]<>0) and (r>way[l,i]) then
     begin
        r:=way[l,i];
     if r>way[x,i] then way[x,i]:=r;
     find(i,r);
     end;
 end;

 begin
   assign(input,'truck.in');reset(input);
   assign(output,'truck.out');rewrite(output);
   readln(n,m);
   for i:=1 to m do
   begin
     readln(x,y,z);
     if z>way[x,y] then
     begin
       way[x,y]:=z;
       way[y,x]:=z;
     end;
   end;
   readln(q);
   for i:=1 to q do
   begin
     readln(x,y);
     find(x,100000);
     long[i]:=way[x,y];
   end;
   for i:=1 to q do
   if long[i]<>0 then
   writeln(long[i])
   else
   writeln('-1');
   readln;
   close(input);close(output);
 end.
