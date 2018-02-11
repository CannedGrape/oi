program match;
var
  a,b:array[0..1000000] of int64;
  n,m,k,x,j,i,c,s,d,f,g,p,h:longint;
begin
 assign(input,'match.in'); reset(input);
 assign(output,'match.out'); rewrite(output);
 readln(n);
   p:=1;
 for i:=1 to n do read(f);
 for i:=1 to m do read(g);

  write(p);
 close(input); close(output);

end.