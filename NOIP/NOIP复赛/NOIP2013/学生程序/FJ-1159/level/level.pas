var a,b,c,e,i,j,k:longint;
    x,y:array[1..1000,1..1000] of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(a,b);
  for i:=1 to a do
  begin
    read(x[i,j]);
  end;
  writelnb();
  close(input);
  close(output);
end.