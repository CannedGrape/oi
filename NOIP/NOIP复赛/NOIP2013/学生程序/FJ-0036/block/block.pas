var n,a,w,ans:int64;
   i:longint;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
  readln(n);
    w:=0;
      for i:=1 to n do
      begin
        read(a);
        if a>w then inc(ans,a-w);
        w:=a;
      end;
  writeln(ans);
close(input);
close(output);
end.


