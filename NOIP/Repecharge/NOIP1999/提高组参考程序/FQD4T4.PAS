{$r-,q-,s-,n+,g+}
program FenQuPrepare_Day4_Task4_FQ99P4;
const
  fn_in='input.txt';
  maxn=40;
  maxmax=10000;
var
  n,k,max:integer;
  s,ans:array[1..maxn] of integer;
  dp:array[0..maxmax] of integer;

  procedure init;
  begin
    readln(n,k);
  end;

  function Count(k:Integer):integer;
  var i,j:Integer;
  begin
    i:=1;
    dp[0]:=0;
    dp[1]:=1;
    while(dp[i]<=n) do
    begin
      inc(i);
      dp[i]:=n+1;
      for j:=1 to k do
        if i-s[j]>=0 then
         if dp[i-s[j]]+1<dp[i] then dp[i]:=dp[i-s[j]]+1;
    end;
    dec(i);
    if i>max then
    begin
      max:=i;
      ans:=s;
    end;
    Count:=i;
  end;

  procedure DFS(d:Integer);
  var i,up:Integer;
  begin
    if d>k then
    begin
      if s[d-1]*n>max then Count(k);
    end else
    begin
      up:=Count(d-1)+1;
      for i:=s[d-1]+1 to up do
      begin
        s[d]:=i;
        dfs(d+1);
      end;
    end;
  end;

  procedure main;
  begin
    s[1]:=1;
    DFS(2);
  end;

  procedure out;
  var i:Integer;
  begin
    for i:=1 to k do
      write(ans[i]:4);
    writeln;
    writeln('MAX=',max);
  end;

  begin
    init;
    main;
    out;
  end.