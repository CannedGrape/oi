var
  p,n,m,k,i,j,x,y:longint;
  a:array[1..10000,1..10000]of longint;
function min(o,p:longint):longint;
begin min:=o;if o>p then min:=p;end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  fillchar(a,sizeof(a),0);
  read(n,m);
  for i:=1 to m do
    begin
      read(x,y,j);
      a[x,y]:=j;
      a[y,x]:=j;
    end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if (i<>j)and(a[i,k]>0)and(a[k,j]>0)then
          if (a[i,k]=0)or(a[i,j]<min(a[i,k],a[k,j]))then a[i,j]:=min(a[i,k],a[k,j]);
  read(p);
  for i:= 1 to p do
    begin
      read(k,j);
      if a[k,j]=0 then writeln(-1)else writeln(a[k,j]);
    end;
  close(input);close(output);
end.
