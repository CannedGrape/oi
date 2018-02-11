var
 ta,ai:int64;
 a,b:array[1..1000000] of int64;
 x,i,n,p:longint;

begin
 assign(input,'number.in'); reset(input);
 assign(output,'number.out'); rewrite(output);
 readln(n,p);

 for i:=1 to n do
  begin
   read(x);
   ta:=ta+x;
   if ta>ai then
    ai:=ta;
   if ta<0 then ta:=0;
   if ta=0 then a[i]:=x
    else a[i]:=ta;
   end;
 b[1]:=a[1]; ta:=b[1]+a[1];
 for i:=2 to n do
  begin
   b[i]:=ta;
   if (b[i]+a[i]>ta)and(i<>n) then ta:=b[i]+a[i];
  end;
 if b[1]>ta then writeln(b[1] mod p)
  else writeln(ta mod p);
 close(input); close(output);
end.
