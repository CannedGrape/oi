program ywt52;
  var num:array[-10..100100] of longint;
      f:array[-10..100100,0..1] of longint;
      n:longint;
function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;
procedure init;
  var i,j:longint;
  begin
    readln(n);
    for i:=1 to n do read(num[i]);
  end;
procedure main;
  var i,j:longint;
  begin
    fillchar(f,sizeof(f),128);
    f[1,1]:=1;
    f[1,0]:=1;
    for i:=2 to n do
      begin
        for j:=1 to i-1 do
          begin
            if num[j]>num[i] then f[i,0]:=max(f[i,0],f[j,1]+1);
            if num[j]<num[i] then f[i,1]:=max(f[i,1],f[j,0]+1);
          end;
        if f[i,0]<0 then f[i,0]:=1;
        if f[i,1]<0 then f[i,1]:=1;
      end;
    write(max(f[n,0],f[n,1]));
  end;
  begin
    assign(input,'flower.in'); reset(input);
    assign(output,'flower.out'); rewrite(output);
    init;
    main;
    close(input);
    close(output);
  end.
