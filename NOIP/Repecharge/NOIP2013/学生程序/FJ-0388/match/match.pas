program match;
var a,b,c,d,n:longint;
w,x,y,z:array[1..100000]of integer;
begin
{ assign(input,'match.in');
 reset(input);
 assign(output,'match.out');
 rewrite(output);}
 read(n);
 d:=0;
 for a:=1 to n do
  read(x[a]);
 for a:=1 to n do
  read(y[a]);
 for a:=1 to n do
  z[a]:=x[a]-y[a];
 for a:=1 to n do
  if (z[a]>0) then
   begin
    for b:=1 to n do
     begin
      if (z[a]>(x[a]-y[b])) and (z[a]>0) then
       begin
        z[a]:=x[a]-y[b];
        c:=y[a];
        y[a]:=y[b];
        y[b]:=c;
        d:=d+1;
       end
     end;
   end;
 write(d);
 close(input);
 close(output);
end.
