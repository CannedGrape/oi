program exam1;
var i,j,n,p,max,maxans,k:longint;
    a,teshu,fen:array[0..1000000] of longint;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
 read(n,p);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do
  begin
   k:=0;
   max:=-maxlongint;
   for j:=1 to i do
    begin
     k:=k+a[j];
     if k>max then max:=k;
    end;
   teshu[i]:=max;
  end;
 fen[1]:=teshu[1];
 for i:=2 to n do
  begin
   k:=0;
   maxans:=-maxlongint;
   for j:=1 to i-1 do
    begin
     k:=fen[j]+teshu[j];
     if k>maxans then maxans:=k;
    end;
   fen[i]:=maxans;
  end;
 max:=-maxlongint;
 for i:=1 to n do if fen[i]>max then max:=fen[i];
 write(max);
close(input);close(output);
end.


