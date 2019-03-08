var a,b,c,n,m,x,y,z:int64;
    i,j:longint;
    ab,ac,ad,ae,ab1:array [0..2000000] of int64;
begin
 assign(input,'number.in');
 assign(output,'number.out');
 reset(input);
 rewrite(output);
 read(n,m);
 for i:=1 to n do
  read(ae[i]);
 ab[1]:=ae[1];
 ab1[1]:=ae[1];
 for i:=2 to n do
  begin
   ab1[i]:=ae[i];
   if ab1[i-1]+ae[i]>ab1[i] then ab1[i]:=ab1[i-1]+ae[i];
   ab[i]:=ae[i];
   if ab[i-1]>ab[i] then ab[i]:=ab[i-1];
   if ab1[i]>ab[i] then ab[i]:=ab1[i];
  end;
 ac[1]:=ab[1];
 ad[1]:=ab[1]*2;
 z:=ac[1];
 for i:=2 to n do
  begin
   ac[i]:=ad[i-1];
   ad[i]:=ad[i-1];
   if ad[i]<ab[i]+ac[i] then ad[i]:=ab[i]+ac[i];
   if ac[i]>z then z:=ac[i];
  end;
 writeln(z);
 close(input);
 close(output);
end.
