var
 i,k,m,n,x,ci,w,h,kk:longint;
begin
 assign(input,'circle.in');reset(input);
 assign(output,'circle.out');rewrite(output);
 readln(n,m,k,x);
 ci:=1;
 w:=x;
 kk:=0;
 repeat
  h:=h+1;
  kk:=(kk+m) mod n;
 until kk=0;
 for i:=1 to k  do
 begin
  ci:=(ci*10) mod h;
 end;
 for i:=1 to ci do
  w:=(w+m) mod n;
 writeln(w);
 close(input);  close(output);
 end.
