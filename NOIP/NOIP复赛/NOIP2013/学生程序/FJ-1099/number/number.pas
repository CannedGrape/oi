uses math;
var
  n,p,i,j:longint;
  maxb,mm:int64;
  a,b,c:array[1..1000001] of int64;
begin
  assign(input,'number.in');assign(output,'number.out');
  reset(input);rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  close(input);
  for i:=1 to n do
   begin
     mm:=0;maxb:=-9999999;
     for j:=i downto 1 do
      begin
        mm:=mm+a[j];
        maxb:=max(maxb,mm);
      end;
     b[i]:=maxb;
   end;
  c[1]:=b[1];
  for i:=2 to n do
   begin
     maxb:=-9999999;
     for j:=1 to i-1 do maxb:=max(maxb,b[j]+c[j]);
     c[i]:=maxb;
   end;
  maxb:=c[1];
  for i:=2 to n do maxb:=max(c[i],maxb);
  writeln(maxb mod p);
  close(output);
end.                              