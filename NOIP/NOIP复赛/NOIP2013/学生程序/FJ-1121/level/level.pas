program level;
var
  a,b:array[1..1010,0..1010] of longint;
  d:array[1..1010,1..1010] of boolean;
  c:array[1..1010] of boolean;
  i,j,k,m,n,s,t:longint;
  bo:boolean;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    read(b[i,0]);
    for j:=1 to b[i,0] do
    begin
      read(b[i,j]);
      d[i,b[i,j]]:=true;
    end;
  end;
  for i:=1 to n do
    for j:=1 to m do
      if (b[j,1]<=i) and (b[j,b[j,0]]>=i) and (d[j,i]=false) then
        for k:=1 to b[j,0] do
          a[b[j,k],i]:=1;
  for i:=1 to n do
    for j:=1 to n do
      if i<>j then if a[i,j]=1 then inc(a[i,0]);
  s:=0;
  while true do
  begin
    s:=s+1;
    for i:=1 to n do
      if (a[i,0]=0) and (c[i]=false) then
      begin
        for j:=1 to n do
          if (i<>j) and (a[j,i]=1) then
          begin
            a[j,i]:=0;
            dec(a[j,0]);
          end;
        c[i]:=true;
      end;
    bo:=false;
    for i:=1 to n do
      if c[i]=false then begin bo:=true; break; end;
    if bo=false then break;
  end;
  writeln(s);
  close(input);
  close(output);
end.
