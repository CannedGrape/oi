var n,m,x,i:longint;
    k,t,j,y,x1:int64;
//_____________________________________
procedure iin;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
end;
procedure oout;
begin
  close(input);
  close(output);
end;
//______________________________________
begin
  iin;
  read(n,m,k,x);
  x1:=n;
  y:=0;
  repeat
   inc(y);
   x1:=x1 div 10;
  until x1<10;
  //if y<=k then
  //begin
  x1:=m;
  for i:=1 to y do x1:=x1*10;
  repeat
   t:=x1 mod n;
   x1:=t*10;
   inc(y);
  until ((t=0)or(y>k));
  //end;
  //if y>k then
   //t:=n;
  j:=(x+(t mod n))mod n;
  write(j);
  oout;
end.
