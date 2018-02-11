program flower;
var h:array[1..200000]of longint;
    n,i,l,r,num,ans:longint;
    bo:boolean;
begin
    assign(input,'flower.in');
    assign(output,'flower.out');
    reset(input);
    rewrite(output);
    readln(n);
    for i:=1 to n do read(h[i]);
    l:=0;
    r:=1;
    num:=0;
    if h[2]<h[1] then bo:=true
    else bo:=false;
    repeat
      l:=r;
      r:=l+1;
      if bo then
      begin
        while (h[r]<=h[r-1]) and (r<=n) do inc(r);
        dec(r);
        num:=r-l-1;
        ans:=ans+num;
      end
      else
      begin
        while (h[r]>=h[r-1]) and (r<=n) do inc(r);
        dec(r);
        num:=r-l-1;
        ans:=ans+num;
      end;
      bo:=not bo;
    until r=n;
    writeln(n-ans);
    close(input);
    close(output);
end.
