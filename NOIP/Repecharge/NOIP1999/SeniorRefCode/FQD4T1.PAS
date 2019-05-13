program FenQuPrepare_Day4_Task1_FQ99P1;
const
  fn_in='input.txt';
  maxn=100;
var
  a:array[1..maxn] of integer;
  h:array[1..maxn] of integer;
  n:integer;

  procedure init;
  begin
    assign(input,fn_in);
    reset(input);
    n:=1;
    read(a[n]);
    while(a[n]>=0) do
    begin
      inc(n);
      read(a[n]);
    end;
    dec(n);
  end;

  procedure solve;
  var i,j:Integer;
  begin
    for i:=1 to n do
    begin
      h[i]:=1;
      for j:=1 to i-1 do
        if (a[j]>=a[i]) and (h[j]+1>h[i]) then h[i]:=h[j]+1;
    end;
    j:=0;
    for i:=1 to n do
      if h[i]>j then j:=h[i];
    writeln(j);

    for i:=1 to n do
    begin
      h[i]:=1;
      for j:=1 to i-1 do
        if (a[j]<a[i]) and (h[j]+1>h[i]) then h[i]:=h[j]+1;
    end;
    j:=0;
    for i:=1 to n do
      if h[i]>j then j:=h[i];
    writeln(j);
  end;

  begin
    init;
    solve;
  end.