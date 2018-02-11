program fuck;
var
 a:array[0..100000] of longint;
 f:Array[0..100000,1..4] of longint;
 i,j,k,l,s,t,m,n:longint;
function max(x,y:longint):longint;
begin
 if x>y then exit(x) else exit(y);
end;
begin
 assign(input,'flower.in');
 assign(output,'flower.out');
 reset(input);
 rewrite(output);
 readln(n);
 for i:=1 to n do
  begin
  read(a[i]);
  f[i,1]:=1;
  f[i,2]:=0;
  f[i,3]:=0;
  f[i,4]:=1;
  end;
 readln;
 s:=1;
 for i:=2 to n do
  begin
   for j:=i-1 downto 1 do
    begin
    if (a[j]>a[i]) and (f[j,2] mod 2=0) then f[i,1]:=max(f[i,1],f[j,2]+1);
    if (a[j]<a[i]) and (f[j,3] mod 2=0) then f[i,4]:=max(f[i,4],f[j,3]+1);
    if (a[j]<a[i]) and (f[j,1] mod 2=1) then f[i,2]:=max(f[i,2],f[j,1]+1);
    if (a[j]>a[i]) and (f[j,1] mod 2=1) then f[i,3]:=max(f[i,3],f[j,4]+1);
    end;
  s:=max(s,max(f[i,1],max(f[i,2],max(f[i,3],f[i,4]))));
  end;
 writeln(s);
 close(input);
 close(output);
end.
