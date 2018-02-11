program ywt52;
  var num1,num2,a,b,now,plan,t,plann:array[-100..100000] of longint;
      n:longint; ans:int64;
procedure init;
  var i,j:longint;
  begin
    readln(n);
    for i:=1 to n do
      begin
        read(a[i]);
        num1[i]:=i;
      end;
    for i:=1 to n do
      begin
        read(b[i]);
        num2[i]:=i;
      end;
  end;
procedure qsort1(l,r:longint);
  var i,j,x,y: longint;
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
            y:=num1[i];
            num1[i]:=num1[j];
            num1[j]:=y;
            inc(i);
            j:=j-1;
          end;
      until i>j;
      if l<j then qsort1(l,j);
      if i<r then qsort1(i,r);
   end;
procedure qsort2(l,r:longint);
  var i,j,x,y: longint;
    begin
      i:=l;
      j:=r;
      x:=b[(l+r) div 2];
      repeat
        while b[i]<x do inc(i);
        while x<b[j] do dec(j);
        if not(i>j) then
          begin
            y:=b[i];
            b[i]:=b[j];
            b[j]:=y;
            y:=num2[i];
            num2[i]:=num2[j];
            num2[j]:=y;
            inc(i);
            j:=j-1;
          end;
      until i>j;
      if l<j then qsort2(l,j);
      if i<r then qsort2(i,r);
   end;
procedure prework;
  var i,j:longint;
  begin
    for i:=1 to n do
      begin
        now[num1[i]]:=num2[i];
        plan[num2[i]]:=num1[i];
      end;
  end;
procedure main;
  var i,j,x:longint;
  begin
    ans:=0;
    for i:=1 to n-1 do
      begin
        inc(ans,abs(now[i]-i));
        ans:=ans mod 99999997;
        for j:=i to now[i]-1 do inc(now[plan[j]]);
      end;
    write(ans);
  end;
  begin
    assign(input,'match.in'); reset(input);
    assign(output,'match.out'); rewrite(output);
    init;
    qsort1(1,n);
    qsort2(1,n);
    prework;
    main;
    close(input);
    close(output);
  end.
