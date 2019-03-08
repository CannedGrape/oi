var
   maxd:array[0..1000,0..1000]of longint;
   n,m,q,a,b,c,i,j,x,y:longint;
function max(a,b:longint):longint;
begin
  if a=0 then
    if b=0 then exit(0)
    else exit(b);
  if b=0 then exit(a);
  if a>b then exit(a);
  exit(b)
end;
function min(a,b:longint):longint;
begin
  if a=0 then exit(0);
  if b=0 then exit(0);
  if a<b then exit(a);
  exit(b)
end;
begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input);
  rewrite(output);
  read(n,m);
  fillchar(maxd,sizeof(maxd),0);
  for i:=1 to m do
    begin
      read(a,b,c);
      maxd[a,b]:=max(maxd[a,b],c);
      maxd[b,a]:=maxd[a,b];
      for j:=1 to n do
        begin
          if j<>a then
            begin
              maxd[a,j]:=max(maxd[a,j],min(maxd[a,b],maxd[b,j]));
              maxd[j,a]:=maxd[a,j];
            end;
          if j<>b then
            begin
              maxd[b,j]:=max(maxd[b,j],min(maxd[a,b],maxd[a,j]));
              maxd[j,b]:=maxd[b,j];
            end;
        end;
    end;
  read(q);
  for i:=1 to q do
    begin
      read(x,y);
      if maxd[x,y]<>0 then
        writeln(maxd[x,y])
      else writeln(-1);
    end;
  close(input);
  close(output)
end.