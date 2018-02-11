//block
var i,j,t,n,ans:longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);j:=0;t:=0;ans:=0;
  for i:=1 to n do
  begin
    read(t);
    if t>j then ans:=ans+t-j;
    j:=t;
  end;
  writeln(ans);
  close(input);close(output);
end.