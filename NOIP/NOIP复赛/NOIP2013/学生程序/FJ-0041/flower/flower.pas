program flower;
var h:array[0.. 100001]of longint;
    f:array[0.. 100001,0..  1,0.. 1,0.. 1]of longint;
    i,j,t,k,n,m,l,r,z,y,x:longint;
    function max(a,b:longint):longint;
    begin
      if a>b then exit(a) else exit(b);
    end;
    procedure init;
    var i:longint;
    begin
      for i:=0 to 1 do
      begin
        f[1,i,1,1]:=1;
        f[1,i,1,0]:=0;
        f[1,i,0,0]:=0;
        f[1,i,0,1]:=0;
      end;
    end;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  fillchar(f,sizeof(f),0);
  init;
  for i:=1 to n do read(h[i]);
  for i:=2 to n do
  begin
    for j:=0 to 1 do
     for k:=0 to 1 do
    begin
      f[i,j,0,k]:=max(f[i-1,j,1,k],f[i-1,j,0,k]);
    end;
    l:=0;r:=0;
    for t:=i-1 downto 1 do
    begin
      if (h[t]<h[i])and(l<f[t,0,1,1]) then
      begin
        l:=f[t,0,1,1];
        break;
      end;
      if (h[t]>h[i])and(r<f[t,0,1,0]) then
      begin
        r:=f[t,0,1,0];
        break;
      end;
    end;
    f[i,0,1,0]:=l+1;
    f[i,0,1,1]:=r+1;
    l:=0;r:=0;
    for t:=i-1 downto 1 do
    begin
      if (h[t]>h[i])and(l<f[t,1,1,1]) then
      begin
        l:=f[t,1,1,1];
        break;
      end;
    end;
    for t:=i-1 downto 1 do
    begin
      if (h[t]<h[i])and(r<f[t,1,1,0]) then
      begin
        r:=f[t,1,1,0];
        break;
      end;
    end;
    f[i,1,1,0]:=l+1;
    f[i,1,1,1]:=r+1;
  end;
  m:=0;
  for j:=0 to 1 do for t:=0 to 1 do for k:=0 to 1 do if f[n,j,t,k]>m then m:=f[n,j,t,k];
  writeln(m);
  close(input);
  close(output);
end.
