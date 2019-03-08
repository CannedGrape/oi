program ys;
uses math;
var
a:array[0..10001,0..10001] of longint;
n,m,q,z,x,y,i,j,maxn,ma,k,mi:longint;
f:array[0..10001] of boolean;
begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
  begin
    readln(x,y,z);
    if z>a[x,y] then
    begin
      a[x,y]:=z;
      a[y,x]:=z;
    end;
  end;
  for i:=1 to (n div 2)+1 do
  begin
    fillchar(f,sizeof(f),true); mi:=0; ma:=0;
    for k:=2 to n do
    begin
      maxn:=0;
      for j:=1 to n do
       if (f[j]) and (a[i,j]>maxn) then begin maxn:=a[i,j]; ma:=j; f[j]:=false; end;
      for j:=1 to n do
      begin
        if (i=j) or (ma=j) then continue;
        mi:=min(a[ma,j],maxn);
        if (mi>a[i,j]) then a[i,j]:=mi;
      end;
    end;
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(x,y);
    if (a[x,y]<>0) and (a[y,x]<>0) then writeln(max(a[x,y],a[y,x]))
     else
      if (a[x,y]<>0) then writeln(a[x,y])
       else if (a[y,x]<>0) then writeln(a[y,x])
       else
     writeln(-1);
  end;
close(input);
close(output);
end.