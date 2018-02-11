var a:array[0..100000]of longint;
    i,j,k,n,y,l,r,mid,num:longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);readln;
    i:=1;j:=1;y:=1;k:=1;
    while i<n do
    begin
      inc(i);
      if (y mod 2=1)and(a[i]>a[j])or(y mod 2=0)and(a[i]<a[j]) then
      begin
        k:=i;j:=i+1;inc(i);inc(y);
      end else
      if (y mod 2=1)and(a[i]<a[k])and(a[i]<a[j])or
          (y mod 2=0)and(a[i]>a[k])and(a[i]>a[j])or
            (y=1)and(a[i]<a[j]) then j:=i;
    end;
    num:=y;
    i:=1;j:=1;y:=1;k:=1;
    while i<n do
    begin
      inc(i);
      if (y mod 2=0)and(a[i]>a[j])or(y mod 2=1)and(a[i]<a[j]) then
      begin
        k:=i;j:=i+1;inc(i);inc(y);
      end else
      if (y mod 2=0)and(a[i]<a[k])and(a[i]<a[j])or
          (y mod 2=1)and(a[i]>a[k])and(a[i]>a[j])or
            (y=1)and(a[i]>a[j]) then j:=i;
    end;
    if y>num then num:=y;
    writeln(num);
  close(input);close(output);
end.
