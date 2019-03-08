var  ans,n,i:longint;
     a:array[0..100050] of longint;
     bo:boolean;

begin
    assign(input,'flower.in'); reset(input);
    assign(output,'flower.out'); rewrite(output);
    readln(n);
    for i:=1 to n do
     read(a[i]);
    ans:=0;
    if a[2]>=a[1] then begin bo:=true; end
     else begin bo:=false;  end;
    i:=2;
    while i<=n do
    begin
      bo:=not bo;
      if not bo then
      begin
       while (i<=n) and (a[i+1]>=a[i]) do
        inc(i);
      end

      else
      begin
       while (i<=n) and (a[i+1]<=a[i]) do
        inc(i);
      end;
      inc(ans);
    end;
    if n>1 then writeln(ans)
     else writeln(1);
    close(input); close(output);
end.
