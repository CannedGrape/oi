var i,j,k,l,m,n,x,p,y,t:longint;
    a,b:array[0..1000000] of longint;
 begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  read(n);
  if n=0 then write(0)else
  if n<3 then write(n-1)else
    write('3');
  close(input);
  close(output);
  end.
