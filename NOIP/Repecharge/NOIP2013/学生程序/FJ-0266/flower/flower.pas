program flower;
  var a:array[1..100000,1..2]of longint;
      b:array[1..100000]of longint;
      i,j,m,n,z,x,y,ans:longint;
  begin
    assign(input,'flower.in');assign(output,'flower.out');
    reset(input);rewrite(output);
    read(m);
    for i:=1 to m do read(b[i]);
    a[1,1]:=1;a[1,2]:=1;
    for i:=2 to m do
    begin
      z:=0;
      for j:=i-1 downto 1 do
      if (b[i]<b[j])and(z<a[j,1]) then z:=a[j,1];
      a[i,2]:=z+1;
      z:=0;
      for j:=i-1 downto 1 do
      if (b[i]>b[j])and(z<a[j,2]) then z:=a[j,2];
      a[i,1]:=z+1;
    end;
    ans:=0;
    for i:=m downto 1 do
    begin
      if a[i,1]>ans then ans:=a[i,1];
      if a[i,2]>ans then ans:=a[i,2];
    end;
    writeln(ans);
    close(input);close(output);
  end.




