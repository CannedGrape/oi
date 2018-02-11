const Ln=100000+10;
var n,c,lc:longint;
    ans:int64;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  //
  readln(n);ans:=0;lc:=0;
  repeat
    read(c);
    if c>lc then inc(ans,c-lc);
    lc:=c;
    dec(n);
  until n=0;
  writeln(ans);
  //
  close(input);close(output);
end.
