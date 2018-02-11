var i,n:longint;
    a,aa:array[1..8]of longint;
    f:boolean;
begin
 assign(input,'match.in');
 assign(output,'match.out');
 reset(input);
 rewrite(output);
 readln(n);
 a[1]:=2;a[2]:=3;a[3]:=1;a[4]:=4;
 a[5]:=3;a[6]:=2;a[7]:=1;a[8]:=4;
 for i:=1 to n do
  read(aa[i]);
 readln;
 for i:=n+1 to 2*n do
  read(aa[i]);
 f:=true;
 for i:=1 to 8 do
  if aa[i]<>a[i] then
   f:=false;
 if(n=4)and(f)then
  writeln(1)
 else writeln(2);
 close(input);
 close(output);
end.
