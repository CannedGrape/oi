program circle;
var i,j,y,n,m,x,q:longint;
    k:longint;
    a:array[-1..1000001] of longint;
begin
  assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input);
  rewrite(output);
    read(n,m,k,x);
    for i:=0 to n-1 do a[i]:=i;
    q:=1;
    if (n mod m <> 0)  then

        for y:=1 to k do
        begin
        q:=q*10;
        q:=q mod n;
        end
    else

        for y:=1 to k do
        begin
        q:=q*10;
        q:=q mod (n div m);
        end;


    for i:= 1 to q do
      for j:=0 to n-1 do
        a[i]:=(a[i]+m) mod n;

    write(a[x]);





close(input);
close(output);

end.
