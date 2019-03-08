var
  b:array[1..30001]of longint;
  a:array[1..4000,1..4000]of longint;
  n,m,i,j,q,x,y,z:longint;
function min(x,y:longint):longint;
  begin
    if x>y then min:=y
           else min:=x;
  end;
function max(x,y:longint):longint;
  begin
    if x>y then max:=x
           else max:=y;
  end;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y,z);
      a[x,y]:=z;
      a[y,x]:=z;
    end;
  readln(q);
  for i:=1 to q do
    begin
      readln(x,y);
      for j:=1 to n do
        if(a[x,j]>0)and(a[j,y]>0) then a[x,y]:=max(min(a[x,j],a[j,y]),a[x,y]);
      if a[x,y]=0 then b[i]:=-1
                  else b[i]:=a[x,y];
    end;
  for i:=1 to q  do  writeln(b[i]);
  close(input);
  close(output);
end.
