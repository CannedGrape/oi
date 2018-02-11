var  n,i,m,minh,maxh,z:longint;
     ans:int64;
     a,b:array[0..100060] of longint;

function max(x,y:longint):longint;
begin
    if x>y then exit(x);
    exit(y);
end;

begin
    assign(input,'block.in'); reset(input);
    assign(output,'block.out'); rewrite(output);
    readln(n);
    for i:=1 to n do
    begin
     read(a[i]);
     if (i=1) or (a[i]<>a[i-1]) then
     begin
      inc(m);
      b[m]:=a[i];
     end;
    end;
    minh:=maxlongint;
    maxh:=b[1];
    for i:=2 to m-1 do
    begin
      if (b[i]<b[i-1]) and (b[i]<b[i+1]) then
      begin
        ans:=ans+maxh-max(b[i],z);
        if b[i]<minh then minh:=b[i];
        if b[i]>z then ans:=ans+b[i]-z;
        z:=b[i];
        maxh:=0;
        continue;
      end;
      if b[i]>maxh then maxh:=b[i];
    end;
    if b[m]>maxh then maxh:=b[m];
    writeln(ans+maxh-z);
    close(input); close(output);
end.

