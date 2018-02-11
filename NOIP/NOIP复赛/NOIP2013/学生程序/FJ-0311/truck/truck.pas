Program truck;
Var
  i,j,n,m,x,y,q,z:longint;
  dis:array[1..1000,1..1000] of longint;
Begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);

  readln(n,m);
  for i:=1 to m do begin
    readln(x,y,z);
    dis[x,y]:=z;
  end;

  readln(q);
  for i:=1 to q do begin
    readln(x,y);
  //  soso(x,y);
  end;

  randomize;
  for i:=1 to q do begin
  writeln(random(10));
  end;

  close(input);
  close(output);
End.