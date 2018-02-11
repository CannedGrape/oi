function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
var n,i,j,zhong,gao,ai,ans:longint;
    f:array[0..100001,1..3] of longint;
    h:array[0..100001] of longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  read(h[1]);
  f[1,2]:=1;
  ans:=1;
  for i:=2 to n do
  begin
    read(h[i]);
    gao:=0;
    zhong:=0;
    ai:=0;
    for j:=i-1 downto 1 do
    begin
      if (h[j]<h[i]) then
      begin
        gao:=max(f[j,2]+1,gao);
        zhong:=max(f[j,3]+1,zhong);
      end
      else
      if (h[j]>h[i]) then
      begin
        ai:=max(f[j,2]+1,ai);
        zhong:=max(f[j,1]+1,zhong);
      end;
    end;
    f[i,1]:=gao;
    f[i,2]:=zhong;
    f[i,3]:=ai;
    if zhong>ans then ans:=zhong;
    if ai>ans then ans:=ai;
    if gao>ans then ans:=gao;
  end;
  writeln(ans);
  close(input);
  close(output);
end.

