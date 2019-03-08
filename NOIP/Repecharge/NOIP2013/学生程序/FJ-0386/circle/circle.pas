program a1;
var a,b:array[0..1000000] of int64;
  n,m,k,x,j,i,c,s,d:longint;
begin
 assign(input,'circle.in'); reset(input);
 assign(output,'circle.out'); rewrite(output);
 readln(n,m,k,x);
 if n=0 then write(0)
 else
 begin
 s:=1; c:=n-1;
 for i:=1 to k do s:=s*10;
 d:=m; i:=0;
 repeat
 inc(i);
 d:=d*i;
 until d mod 10=0;
 s:=s mod d;
 for i:=0 to c do
 begin
 a[i]:=i;
 b[i]:=a[i];
 end;
 j:=0;
  repeat
  inc(j);
  for i:=0 to c do a[(i+m)mod n]:=b[i];
  for i:=0 to c do b[i]:=a[i];
  until j=s;
 write(a[x]);
 end;
 close(input); close(output);
end.
