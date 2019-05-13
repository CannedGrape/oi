var
  ans,n:longint;

  procedure dfs(m:longint);
  var i:longint;
  begin
  	inc(ans);
    for i:=1 to m div 2 do dfs(i);
  end;
  
  begin
  	read(n);
  	dfs(n);
    writeln(ans);
  end.
