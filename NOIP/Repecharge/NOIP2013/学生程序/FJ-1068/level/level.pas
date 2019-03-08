program level;
  var n,m,ans:integer;
  var a:array[1..1000]of integer;
procedure init;
  var i,j,t,temp:integer;
  begin
    assign(input,'level.in');reset(input);
    readln(n,m);
    for i:=1 to m do
    begin
      read(t);
      for j:=1 to t do
      begin
        read(temp);
        a[temp]:=a[temp]+1;
      end;
    end;
    close(input);
  end;
procedure work;
  var i,j:integer;
  var b:array[1..1000]of boolean;
  begin
    fillchar(b,sizeof(b),true);
    ans:=0;
    for i:=1 to n do
    if b[a[i]] then
    begin
      inc(ans);
      b[a[i]]:=false;
    end;
  end;
procedure print;
  begin
    assign(output,'level.out');rewrite(output);
    writeln(ans);
    close(output);
  end;
begin
  init;
  work;
  print;
end.

