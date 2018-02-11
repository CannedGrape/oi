program level;
var n,m,i,j,p,h,k,d,i1:longint;
    bo:boolean;
    s,c:array[1..1000,1..1000] of longint;
    b:array[1..1000,1..2] of longint;
    a,js:array[1..1000] of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    read(a[i]);
    for j:=1 to p do
    begin
      read(s[i,j]);
      inc(js[s[i,j]]);
      if j=1 then b[i,1]:=s[i,j]
      else if j=p then b[i,2]:=s[i,j];
    end;
  end;
  h:=1;
  for i:=1 to m do
  begin
    d:=0;
      for j:=1 to m do
      for k:=2 to a[i]-1 do
      if i=s[i,k] then
      begin

        for i1:=1 to d do
          if c[i,i1]=s[i,k] then
            bo:=false;
        if bo then begin d:=d+1; c[i,d]:=s[i,k]; end;
      end;
    a[i]:=d;
  end;
  for i:=1 to n do
  if js[i]<>0 then inc(p);
  for i:=1 to m do
    if a[i]=p then begin write(m); halt; end;
  write(m+1);
  close(input);
  close(output);
end.

