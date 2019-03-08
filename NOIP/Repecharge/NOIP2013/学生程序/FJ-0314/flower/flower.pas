var n,i,j,ans:longint;
  a:array[0..100000]of longint;
  f:array[0..100000,1..4]of longint;
  function max(a,b:longint):longint;
    begin
      if a>b then max:=a
      else max:=b;
    end;
  begin
    assign(input,'flower.in');reset(input);
    assign(output,'flower.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);
    for i:=2 to n do
      begin
        f[i,1]:=1; f[i,2]:=1; f[i,3]:=1; f[i,4]:=1;
        for j:=1 to i-1 do
          begin
            if a[j]<a[i] then f[i,1]:=max(f[i,1],f[i,2]+1);
            if a[j]>a[i] then f[i,2]:=max(f[i,2],f[i,1]+1);
            if a[j]<a[i] then f[i,3]:=max(f[i,3],f[i,4]+1);
            if a[j]>a[i] then f[i,4]:=max(f[i,4],f[i,3]+1);
          end;
        ans:=max(ans,max(max(f[i,1],f[i,2]),max(f[i,3],f[i,4])));
      end;
    write(ans);
    close(input);
    close(output);
  end.
