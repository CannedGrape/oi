var n,i,ans:longint;
    h,g:array[1..100000]of longint;
procedure dfsmax(k,date:longint);
  begin
    if k>n then
      begin
        if date>ans then ans:=date;
        exit;
      end;
    if date+(n-k+1)<=ans then exit;
    if date=0 then
      begin
        g[date+1]:=h[k];
        dfsmax(k+1,date+1);
      end
    else
      begin
        if date mod 2=0 then
          if h[k]>g[date] then
            begin
              g[date+1]:=h[k];
              dfsmax(k+1,date+1);
            end
        else
          if h[k]<g[date] then
            begin
              g[date+1]:=h[k];
              dfsmax(k+1,date+1);
            end;
      end;
    dfsmax(k+1,date);
  end;
procedure dfsmin(k,date:longint);
  begin
    if k>n then
      begin
        if date>ans then ans:=date;
        exit;
      end;
    if date+(n-k+1)<=ans then exit;
    if date=0 then
      begin
        g[date+1]:=h[k];
        dfsmin(k+1,date+1);
      end
    else
      begin
        if date mod 2=0 then
          if h[k]<g[date] then
            begin
              g[date+1]:=h[k];
              dfsmin(k+1,date+1);
            end
        else
          if h[k]>g[date] then
            begin
              g[date+1]:=h[k];
              dfsmin(k+1,date+1);
            end;
      end;
    dfsmin(k+1,date);
  end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  dfsmax(1,0);
  dfsmin(1,0);
  writeln(ans);
  close(input);close(output);
end.
