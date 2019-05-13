program hut;
var
m,n     : integer;
a       : array[1..100,1..100,0..100] of double;
k1,k2   : double;
i,j,k   : longint;
v1      : array[1..100,0..100] of double;
procedure calca;
   var
   i,j,k,l,o,tk
        : integer;
   min  : double;
   begin
   for i:= 1 to 100 do
      for j:= 0 to 100 do a[i,1,j]:= v1[i,j]+k1*i*i;
   n:= n-m;
   for i:= 2 to 100 do
      for j:= 2 to i do
         for k:= 0 to n do begin
            a[i,j,k]:= 1e10;
            for l:= i-i div j to i-1 do begin
                if (i=100)and(l=50) then
                   n:= n;
                min:= 1e10; tk:= k;
                if tk>i-l-1 then tk:= i-l-1;
                for o:= 0 to tk do
                   if a[i-l,1,o]+a[l,j-1,k-o]<min then
                      min:= a[i-l,1,o]+a[l,j-1,k-o]
                   else break;
                if min<a[i,j,k] then a[i,j,k]:= min;
                end;
            end;
   end;
procedure calcv1;
   var
   i,j,k: integer;
   begin
   for i:= 1 to 100 do v1[i,0]:= k2*i*i;
   for i:= 2 to 100 do begin
      for j:= 1 to i-1 do begin
         v1[i,j]:= 1e30;
         for k:= j to i-1 do begin
            if k2*(i-k)*(i-k)+v1[k,j-1]<v1[i,j] then
               v1[i,j]:= k2*(i-k)*(i-k)+v1[k,j-1];
            end;
         end;
      for j:= i to 100 do v1[i,j]:= v1[i,j-1];
      end;
   end;
begin
assign(input,'hut.in'); reset(input);
read(k1,k2,m,n);
calcv1;
calca;
assign(output,'hut.out'); rewrite(output);
writeln(a[100,m,n]:0:1);
close(output);
end.
