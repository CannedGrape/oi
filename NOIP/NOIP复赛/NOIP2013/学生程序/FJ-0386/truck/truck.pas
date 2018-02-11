program truck;
var
  a,b:array[0..1000000] of int64;
  n,m,k,x,j,i,c,s,d,f,g,p,h:longint;
begin
 assign(input,'truck.in'); reset(input);
 assign(output,'truck.out'); rewrite(output);
 readln(n,m);
 s:=1; c:=n-1; p:=-1;
 for i:=1 to m do readln(f,g,h);
 read(m);
 for i:=1 to m do read(f,g);
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
  write(p);
 close(input); close(output);

end.