program ywt52;
  var num,pos,a:array[-10..100100] of longint;
      n:longint;  ans:int64;
procedure init;
  var i,j:longint;
  begin
    readln(n);
    for i:=1 to n do read(num[i]);
    for i:=1 to n do
      begin
        a[i]:=num[i];
        pos[i]:=i;
      end;
  end;
procedure sort(l,r:longint);
  var i,j,x,y:longint;
  begin
    i:=l;
    j:=r;
    x:=a[(l+r) div 2];
    repeat
      while a[i]<x do inc(i);
      while x<a[j] do dec(j);
      if not(i>j) then
        begin
          y:=a[i];
          a[i]:=a[j];
          a[j]:=y;
          y:=pos[i];
          pos[i]:=pos[j];
          pos[j]:=y;
          inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
procedure main;
  var i,j,now,x,l,r,y:longint;
  begin
    ans:=0; now:=0;
    for i:=1 to n do
      begin
        x:=pos[i]; y:=num[x];
        ans:=ans+y;
        l:=x; r:=x;
        while (num[l-1]>0) and (l-1>0) do dec(l);
        while (num[r+1]>0) and (r+1<=n) do inc(r);
        for j:=l to r do dec(num[j],y);
      end;
    write(ans);
  end;
  begin
    assign(input,'block.in'); reset(input);
    assign(output,'block.out'); rewrite(output);
    init;
    sort(1,n);
    main;
    close(input);
    close(output);
  end.
