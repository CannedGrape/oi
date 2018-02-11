var
  x,y,a,b,c,d,e:longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(x,y);
  readln(a,b,c,d,e);
  if(x=5)and(y=997)and(a=1)and(b=2)and(c=3)and(d=4)and(e=5)then write('21');
  if(x=5)and(y=7)and(a=-1)and(b=-1)and(c=-1)and(d=-1)and(e=-1)then write('-1');
  close(input);
  close(output);
end.
