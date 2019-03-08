var a:array[0..1000,0..1000]of longint;
    i,j,k,n,m,q,x,y,z:longint;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
    fillchar(a,sizeof(a),$ff);
    readln(n,m);
    for i:=1 to m do
    begin
      readln(x,y,z);
      if z>a[x,y] then
      begin
        a[x,y]:=z;a[y,x]:=z;
      end;
    end;
    for i:=1 to n do a[i,i]:=0;
    for k:=1 to n do
      for i:=1 to n do
        for j:=1 to n do
        begin
          if a[i,k]<a[k,j] then x:=a[i,k] else x:=a[k,j];
          if x>a[i,j] then a[i,j]:=x;
        end;
    readln(q);
    for i:=1 to q do
    begin
      readln(x,y);writeln(a[x,y]);
    end;
  close(input);close(output);
end.