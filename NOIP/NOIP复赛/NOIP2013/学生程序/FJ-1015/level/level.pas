program a123;
var a,level:array[1..1000] of integer;
    b:array[1..1000,1..1000] of integer;
    i,j,k,m,n,ans,max,min,x:integer;
    c:boolean;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  min:=-maxint;
  max:=0;
  ans:=1;
  fillchar(b,sizeof(b),0);
  fillchar(level,sizeof(level),0);
  readln(n,m);
  for i:=1 to m do
  begin
    read(a[i]);
    for j:=1 to a[i]-1 do
    begin
      read(b[i,j]);
    end;
    readln(b[i,a[i]]);
  end;
  if a[1]<>n then ans:=ans+1;
  for i:=1 to a[1] do
  begin
    inc(level[i]);
    if i>max then max:=i;
    if i<min then min:=i;
  end;
  for i:=2 to m do
  begin
    for j:=2 to a[i] do
    begin
      if (b[i,a[i]]<=max) and (b[i,1]<min) and ([i,j]=0) then c:=true;
        if b[i,j]>max then max:=j;
        if b[i,j]<min then min:=j;
      end;
    end;
    if c=true then ans:=ans+1;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
