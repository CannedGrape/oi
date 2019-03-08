program ywt52;
  var num:array[-10..1000000] of longint;
      b:array[-10..1000000] of boolean;
      n,m,k,x,len:longint; big:int64;
procedure init;
  var i,j,y:longint;
  begin
    readln(n,m,k,x);
    fillchar(b,sizeof(b),false);
    len:=-1; y:=x;
    while not(b[y]) do
      begin
        b[y]:=true;
        inc(len);
        num[len]:=y;
        y:=(y+m) mod n;
      end;
  end;
procedure main;
  var i,j,left:longint; t:int64;
  begin
    left:=k;
    t:=10; big:=1;
    while left>0 do
      begin
        if (left and 1)=1 then
          begin
            big:=(big*t) mod (len+1);
          end;
        t:=(t*t) mod (len+1);
        left:=left shr 1;
      end;
    big:=big mod (len+1);
    write(num[big]);
  end;
  begin
    assign(input,'circle.in'); reset(input);
    assign(output,'circle.out'); rewrite(output);
    init;
    main;
    close(input);
    close(output);
  end.
