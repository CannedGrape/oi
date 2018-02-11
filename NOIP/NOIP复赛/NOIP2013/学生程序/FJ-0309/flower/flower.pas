program jk;
vaR h,a,b:array[0..100000]of longint;
    i,j,max,n:longint;
  BEGIN
    assign(input,'flower.in');reset(input);
    assign(output,'flower.out');rewrite(output);
    read(n);
    for i:=1 to n do read(h[i]);
    for i:=1 to n do
      begin
        a[i]:=1;b[i]:=1;
        for j:=i-1 downto 1 do
          begin
            if a[j]>=a[i] then
              begin
                if a[j] and 1=1 then
                  begin if h[i]>h[j] then a[i]:=a[j]+1; end
                else
                  begin if h[i]<h[j] then a[i]:=a[j]+1; end;
              end;
            if b[j]>=b[i] then
              begin
                if b[j] and 1=1 then
                  begin if h[i]<h[j] then b[i]:=b[j]+1; end
                else
                  begin if h[i]>h[j] then b[i]:=b[j]+1; end
              end;
          end;
      end;
    for i:=1 to n do
      begin
        if a[i]>max then max:=a[i];
        if b[i]>max then max:=b[i];
      end;
    write(max);
    close(input);close(output);
  end.
