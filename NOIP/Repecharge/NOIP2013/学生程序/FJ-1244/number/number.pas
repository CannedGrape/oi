program hlh;
var  c,a,d:array[1..1000]of longint;
     n,m,i,j,f,ans:longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  read(n,m);
  for i:=1 to n do read(a[i]);
  fillchar(f,sizeof(f),0);
  c[1]:=a[1];d[1]:=a[1];
  for i:=2 to n do
  begin
    ans:=0;
    if i=2 then c[i]:=a[i-1];
    for j:=i-1 downto 1 do
    begin
      if c[j]>ans then ans:=c[j];
    end;
    if ans+a[i]>ans then c[i]:=ans+a[i]
    else c[i]:=ans;
    ans:=0;
    for j:=i-1 downto 1 do
    begin
      if d[j]>ans then ans:=d[j];
    end;
    if i<>2 then d[i]:=d[i]+c[i-1]+ans;
    if i=2 then d[i]:=c[1]+d[1];
  end;
  ans:=0;
  for i:=1 to n do
  if d[i]>ans then
  begin
  ans:=d[i];
  end;
  if ans<0 then
  begin
  write('-');
  ans:=-ans;
  end;
  if ans<m then write(ans)
  else write(ans mod m );
  close(input);close(output);
end.


