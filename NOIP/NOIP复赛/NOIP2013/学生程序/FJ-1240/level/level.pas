program level;
var a:array[0..1000,0..1000] of longint;
    i,j,p,x,ans,n,m:longint;
    pp:boolean;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  read(n,m);
  for i:=1 to m do
  begin
    read(a[i,0]);
    for j:=1 to a[i,0] do
    begin
      read(x);
      a[i,x]:=1;
    end;
  end;
  for i:=1 to m do
    for j:=1 to n do
      if a[i,j]=1 then
      begin
        p:=j+1;
        while (a[i,p]<>1) and (p<n) do
        begin
          a[i,p]:=-1;
          inc(p);
        end;
      end;
  for i:=1 to m do
    for j:=n downto 1 do
      if a[i,j]<>1 then a[i,j]:=0
      else break;
  ans:=1;
  for i:=1 to n do
  begin
    pp:=true;
    for j:=1 to m-1 do
      if (a[i,j]<>a[i+1,j]) and ((a[i,j]=-1) or (a[i+1,j]=-1)) then pp:=false;
    if pp=false then inc(ans);
  end;
  write(ans+1);
  close(input);
  close(output);
end.
