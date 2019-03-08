program count;
var s,sb:ansistring;
    i,n,j,v,x:longint;
begin
  assign(input,'count.in');
    reset(input);
  assign(output,'count.out');
    rewrite(output);
  readln(n,x);
  s:='1'; j:=0;
  for i:=2 to n do
    begin
      str(i,sb);
      insert(sb,s,0);
      sb:=' ';
    end;
  for i:=1 to length(s) do
    begin
      val(s[i],v);
      if v=x then j:=j+1;
    end;
     writeln(j);
  close(input);close(output);
end.
