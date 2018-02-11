program block;
var h:array[1..200000]of longint;
    n,i,l,r,min:longint;
    ans:int64;
begin
    assign(input,'block.in');
    assign(output,'block.out');
    reset(input);
    rewrite(output);
    readln(n);
    for i:=1 to n do read(h[i]);
    ans:=0;
    repeat
      l:=1;
      r:=1;
      while (h[l]=0) and (l<n) do inc(l);
      if (l=n) and (h[n]=0) then break;
      if r<=l then r:=l;
      min:=maxlongint;
      while (h[r]>0) and (r<=n) do
      begin
        if h[r]<min then min:=h[r];
        inc(r);
      end;
      ans:=ans+min;
      if h[r]=0 then dec(r);
      for i:=l to r do h[i]:=h[i]-min;
    until false;
    writeln(ans);
    close(input);
    close(output);
end.
