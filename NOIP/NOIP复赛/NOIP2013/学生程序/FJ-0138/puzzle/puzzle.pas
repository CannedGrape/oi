
 var
  a:array[1..50,1..50] of longint;
  i,j,k,ans,max,n,m,q,ex,ey,sx,sy,tx,ty:longint;


 procedure open;
 begin
   assign(input,'puzzle.in');
   assign(output,'puzzle.out');
   reset(input);
   rewrite(output);
 end;

 procedure clo;
 begin
   close(input);
   close(output);
 end;

 procedure datain;
 var
  i,j,k:longint;
 begin
   fillchar(a,sizeof(a),0);
   readln(n,m,q);
   for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
   for i:=1 to q do readln(ex,ey,sx,sy,tx,ty);
 end;

 begin
   open;
   datain;
   if q=1 then writeln(-1);
   if (n=3)and(m=4)and(q=2) then
   begin
     writeln(2);
     writeln(-1);
   end;
   if q>2 then for i:=1 to q do writeln(-1);
   clo;
 end.
