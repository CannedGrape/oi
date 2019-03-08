var
  n,m,i,j,k,djs,ans:longint;
  hctd:array[1..1000,1..100000]of integer;
  hctc:array[1..1000]of integer;
  cztc,cz:array[1..100000]of longint;
begin
 assign(input,'level.in');reset(input);
 assign(output,'level.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do begin
    read(hctc[i]);djs:=0; while not eoln do begin
      inc(djs);read(hctd[i,djs]);end;end;
  for i:=1 to m do
    for j:=1 to n do
      for k:=1 to n do
      if hctd[i,j]=k then inc(cztc[k]);
  for i:=1 to m do
    for j:=1 to n do
      if cztc[j]=i then begin
        ans:=ans+1;
        break;
        end;
  writeln(ans);
 close(input);close(output);
end.
