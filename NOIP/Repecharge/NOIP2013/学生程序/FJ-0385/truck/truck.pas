program truck;

var i,n,m,x,y,q:longint;
    a:array[-1..20000,-1..20000] of longint;
begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input);
  rewrite(output);
    readln(n,m);
    for i:=1 to 3 do begin read(x,y);readln(a[x,y]); a[y,x]:=a[x,y];end;
    readln(q);
    for i:= 1to q do
    begin
      readln(x,y);
      if a[x,y]<>0 then writeln(a[x,y])
        else writeln(-1);

    end;


  close(input);
  close(output);


end.
