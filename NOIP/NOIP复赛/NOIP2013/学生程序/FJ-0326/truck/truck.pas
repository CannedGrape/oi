var i,n,m,x,y,q,j,max,k,z:longint;
    bo:boolean;
    a:array[0..10001,0..1001] of longint;

procedure swap(a,b:longint);
var t:longint;
begin
  if a>b then exit
  else begin
    t:=a;a:=b;b:=t;
  end;
end;

begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    swap(x,y);
    a[x,y]:=z;
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(x,y);
    swap(x,y);
    bo:=false;
    for j:=1 to y-1 do
    begin
      max:=0;
      if a[j,y]>max then
      begin
        bo:=true;
        max:=a[j,y];
        k:=j;
      end;
    end;
    if bo=false then writeln('-1')
    else writeln(max);
  end;
  close(input);close(output);
end.