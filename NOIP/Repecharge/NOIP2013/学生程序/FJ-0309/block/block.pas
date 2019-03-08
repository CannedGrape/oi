PROGRAM KJ;
VAR i,n,maxt:longint;
    ans:int64;
    a:array[-5..100005]of longint;
  function max(x,y:longint):longint;
    begin if x>y then exit(x) else exit(y); end;
  procedure dfs(l,r:longint);
  var j,i:longint;
    begin
      if l>r then exit;
      if r=l then begin ans:=ans+a[r];exit; end;
      if r-l=1 then begin ans:=ans+max(a[r],a[l]);exit; end;
      inc(ans);j:=l;
      for i:=l to r do
        begin
          dec(a[i]);
          if a[i]<=0 then
            begin
              if j<=i-1 then
                dfs(j,i-1);
              j:=i+1;
            end;
        end;
      dfs(j,r);
    end;
  begin
    assign(input,'block.in');reset(input);
    assign(output,'block.out');rewrite(output);
    read(n);
    ans:=0;
    for i:=1 to n do
      begin read(a[i]);
            if a[i]>maxt then maxt:=a[i]; end;
    if maxt=0 then write('0')
    else
      begin dfs(1,n);
            write(ans); end;
    close(input);close(output);
  end.
