program exam1;
 var a:array[0..150,0..150]of longint;
     b:array[0..150]of integer;
     i,j,k,l,m,n,x,y,o,p,q,yy:longint;
 begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
  read(n,m);yy:=0;
  for i:=1 to m do
   begin
    read(x);p:=0;
    for j:=1 to x do
     begin
      read(a[i,j]);
      o:=0;
      for k:=1 to y do
       if (b[k]=a[i,j]) then
        begin
         o:=1;
         break;
        end;
      if (o=0)and(p=0) then begin yy:=yy+1;p:=1; end;
      if (o=0)then begin y:=y+1;b[y]:=a[i,j]; end;
     end;
   end;
  if y<>n then yy:=yy+1;
  write(yy);
close(input);close(output);
 end.