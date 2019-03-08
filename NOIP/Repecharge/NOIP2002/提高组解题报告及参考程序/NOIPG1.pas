program NOIPG1;
  const
    maxn=100;
  var
    i,j,n,step:integer;ave:longint;
    a:array[1..maxn]of integer;
    f:text;filename:string;
  begin
    write('Input filename:');readln(filename);
    assign(f,filename);reset(f);
    readln(f,n);ave:=0;
    for i:=1 to n do begin
      read(f,a[i]);
      inc(ave,a[i]);
    end;
    ave:=ave div i;
    for i:=1 to n do dec(a[i],ave);
    i:=1;j:=n;
    while a[i]=0 do inc(i);
    while a[j]=0 do dec(j);
    while (i<j) do begin
      inc(a[i+1],a[i]);
      a[i]:=0;
      inc(step);
      inc(i);
      while a[i]=0 do inc(i);
    end;
    writeln(step);
  end.
