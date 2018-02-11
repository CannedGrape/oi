var n,i,j,s,t:longint;
    a,b:array[1..100000,1..3]of longint;
begin
assign(input,'match.in'); reset(input);
assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do begin read(a[i,1]); a[i,2]:=i; end;
  for i:=1 to n do begin read(b[i,1]); b[i,2]:=i; end;
  for i:=1 to n do
    for j:=1 to n do
      if a[i,1]<a[j,1] then
        begin t:=a[i,1]; a[i,1]:=a[j,1]; a[j,1]:=t;
              t:=a[i,2]; a[i,2]:=a[j,2]; a[j,2]:=t; end;

  for i:=1 to n do
    for j:=1 to n do
      if b[i,1]<b[j,1] then
        begin t:=b[i,1]; b[i,1]:=b[j,1]; b[j,1]:=t;
              t:=b[i,2]; b[i,2]:=b[j,2]; b[j,2]:=t; end;

  for i:=1 to n do begin a[i,3]:=i; b[i,3]:=i; end;

  for i:=1 to n do
    for j:=1 to n do
      if a[i,2]<a[j,2] then
        begin t:=a[i,3]; a[i,3]:=a[j,3]; a[j,3]:=t;
              t:=a[i,2]; a[i,2]:=a[j,2]; a[j,2]:=t; end;

  for i:=1 to n do
    for j:=1 to n do
      if b[i,2]<b[j,2] then
        begin t:=b[i,3]; b[i,3]:=b[j,3]; b[j,3]:=t;
              t:=b[i,2]; b[i,2]:=b[j,2]; b[j,2]:=t; end;

  s:=0;
  for i:=1 to n do if a[i,3]<>b[i,3] then s:=s+1;
  writeln(s div 2);
close(input); close(output);

end.