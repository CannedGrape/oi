var
  i,j,n,t,p,cur:longint;
  k:boolean;
  a,b:array[0..100100,0..2] of longint;

begin
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);

  read(n);
  for i:= 1 to n do
    begin read(a[i,0]); a[i,1]:=i; end;
  for i:= 1 to n do
    begin read(b[i,0]); b[i,1]:=i; end;

  for i:= 1 to n-1 do
  begin
    t:=a[a[i,1],0]; p:=i;
    for j:= i+1 to n do
      if a[a[j,1],0]>t then
        begin t:=a[a[j,1],0]; p:=j; end;
    t:=a[i,1]; a[i,1]:=a[p,1]; a[p,1]:=t;
  end;

  for i:= 1 to n-1 do
  begin
    t:=b[b[i,1],0]; p:=i;
    for j:= i+1 to n do
      if b[b[j,1],0]>t then
        begin t:=b[b[j,1],0]; p:=j; end;
    t:=b[i,1]; b[i,1]:=b[p,1]; b[p,1]:=t;
  end;

  for i:= 1 to n do
  begin
    a[i,2]:=b[i,1];
    b[i,2]:=a[i,1];
  end;

  k:=true; cur:=0;
  while k do
  begin
    k:=false;
    for i:= 1 to n-1 do
      if (a[i+1,1]>a[i+1,2]) and (a[i,1]<a[i,2]) then
        begin
          inc(cur); k:=true;
          t:=a[i+1,1]; a[i+1,1]:=a[i,1]; a[i,1]:=t;
          t:=b[a[i+1,1],2]; b[a[i+1,1],2]:=b[a[i,1],2]; b[a[i,1],2]:=t;
        end;
    for i:= 1 to n-1 do
      if (b[i+1,1]>b[i+1,2]) and (b[i,1]<b[i,2]) then
        begin
          inc(cur); k:=true;
          t:=b[i+1,1]; b[i+1,1]:=b[i,1]; b[i,1]:=t;
          t:=a[b[i+1,1],2]; a[b[i+1,1],2]:=a[b[i,1],2]; a[b[i,1],2]:=t;
        end;
  end;

  write(cur);
  close(input); close(output);
end.


