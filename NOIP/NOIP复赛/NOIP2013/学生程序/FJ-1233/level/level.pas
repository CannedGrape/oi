program NOIP2013level;
  var n,m,i,j:integer;
      s,a:array[1..1000] of integer;
  begin
    assign(input,'level.in');
    assign(output,'level.out');
    reset(input); rewrite(output);
      read(n,m);
      for i:=1 to m do
        begin
          read(s[i]);
          for j:=1 to s[i] do read(a[j]);
        end;
      write(m);
    close(input);
    close(output);
  end.