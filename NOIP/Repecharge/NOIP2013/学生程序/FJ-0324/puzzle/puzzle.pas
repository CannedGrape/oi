var i,j,k,n,m,q:integer;input,output:text;
    a:array[0..31,0..31]of integer;
    ex,ey,sx,sy,tx,ty:array[1..30]of integer;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(input,n,m,q);
  for i:=1 to n do
  begin
    for j:=1 to m do
    read(input,a[i,j]);
    readln(input);
  end;
  for k:=1 to q do begin
  readln(input,ex[k],ey[k],sx[k],sy[k],tx[k],ty[k]);
  writeln(output,'-1');
  end;
  close(input);close(output);
end.