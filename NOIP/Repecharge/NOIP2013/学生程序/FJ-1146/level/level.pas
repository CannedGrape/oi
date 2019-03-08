var i,j,k,m,n,o,p,q,l,r,sum,tmp:longint;
    a:array[1..1000,0..1000] of longint;
    f:array[1..1000] of longint;
    b:array[1..1000] of boolean;
    bo,w:boolean;
begin
assign(input,'level.in');
assign(output,'level.out');
reset(input);
rewrite(output);
  read(n,m);
  for i:=1 to n do f[i]:=1;
  for i:=1 to m do begin
    read(a[i,0]);
    bo:=false;
  end;
  write(m);
close(input);
close(output);
end.
