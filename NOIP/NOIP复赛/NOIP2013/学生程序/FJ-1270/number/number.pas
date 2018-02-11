var a,b,c:array[0..100000] of longint;
    i,j,k,n,m,s,t,max:longint;
  begin
    assign(input,'number.in');
    reset(input);
    assign(output,'number.out');
    rewrite(output);
    readln(n,m);
    for i:=1 to n do
    read(a[i]);
    for i:=1 to n do
    begin
    max:=-maxlongint;
    s:=0;
    j:=0;
    for k:=1 to i do
    while j<k do
    begin
    inc(j);
    s:=s+a[j];
    if s>max then max:=s;
    end;
    b[i]:=max;
    end;
    c[1]:=b[1];
    for i:=2 to n do
    begin
    max:=-maxlongint;
    for j:=1 to i-1 do
    begin
    if b[j]+c[j]>max
    then max:=b[j]+c[j];
    end;
    c[i]:=max;
    end;
    max:=-maxlongint;
    for i:=1 to n do
    if c[i]>max then max:=c[i];
    write(max mod m);
    close(input);
    close(output);
    end.
