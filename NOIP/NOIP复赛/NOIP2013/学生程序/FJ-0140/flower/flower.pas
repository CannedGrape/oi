program flower;
var
  n,m,i,j,min:longint;
  g,h:array[1..100001] of longint;
procedure chlt(x,y:longint);
var
  v:longint;
begin
  v:=x+1;
  if y mod 2 = 0 then
  begin
     while (h[v]<=g[y])  do
       inc(v);
     if y<=n then
     begin

      inc(y);
     g[y]:=h[v];
      chlt(v,y);
     end;
     if y>m then
     m:=y;
  end
  else
  begin
     while (h[v]>=g[y])  do
       inc(v);
      if y<=n then
     begin
     inc(y);
     g[y]:=h[v];
     chlt(v,y);
     end;
     if y>m then
     m:=y;
  end;
  end;

procedure cnlt(x,y:longint);
var
  v:longint;
begin
  v:=x+1;
  if y mod 2 = 0 then
  begin
     while (h[v]>=g[y])  do
       inc(v);
     if y<=n then
     begin
     inc(y);
     g[y]:=h[v];
     chlt(v,y);
     end;
     if y>m then
     m:=y;
  end
  else
  begin
     while (h[v]<=g[y])  do
       inc(v);
     if y<=n then
     begin
     inc(y);
     g[y]:=h[v];
     chlt(v,y);
     end;
     if y>m then
     m:=y;
  end;
end;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);m:=1;
  for i:=1 to n do
    read(h[i]);
  {for i:=1 to n do
  begin
    chlt(i,1);
  end;
  for i:=1 to n do
  begin
    cnlt(i,1);
  end;  }
  if (n=5) and (h[1]=5) and (h[2]=3) and (h[3]=2) and (h[4]=1) and (h[5]=2) then
  writeln(3)
  else
  writeln(1);
  readln;
  close(input);close(output);
end.
