var a:array[0..7000,0..7000]of longint;
    n,m,i,j,k,i1,j1,x,y,z,q:longint;
begin
assign(input,'truck.in'); reset(input);
assign(output,'truck.out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do a[i,j]:=-1;
  for i:=1 to m do
    begin
      readln(x,y,z);
      if a[x,y]<z then begin a[x,y]:=z; a[y,x]:=z; end;
    end;
  for i:=1 to n do
    for j:=1 to n do
      if a[i,j]<>-1 then
        for k:=1 to n do
          if (a[i,k]<a[j,k]) and (a[i,j]>a[i,k]) then
            if a[j,k]<a[i,j]
              then begin a[i,k]:=a[j,k]; a[k,i]:=a[j,k]; end
              else begin a[i,k]:=a[i,j]; a[k,i]:=a[i,j]; end;
  readln(q);
  for i:=1 to q do
    begin readln(x,y);
          if x<y then writeln(a[x,y]) else writeln(a[y,x]); end;
close(input); close(output);
end.
