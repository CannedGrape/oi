var n,i,j,ans:longint;
    h,f,g:array[0..100010]of longint;
function max(a,b:longint):longint;
begin
  if a>b then max:=a else max:=b;
end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  fillchar(f,sizeof(f),0);
  fillchar(g,sizeof(g),0);
  if n>1 then
    if h[1]<h[2] then g[1]:=1 else
    if h[1]>h[2] then f[1]:=1;
  ans:=1;
  for i:=2 to n do
  begin
    if h[i]<h[i-1] then
    begin
      for j:=i-1 downto 1 do
        if h[j]<h[i] then break;
      f[i]:=max(f[i],g[j]+1);
      g[i]:=max(g[i],f[i-1]+1);
    end else
    if h[i]>h[i-1] then
    begin
      f[i]:=max(f[i],g[i-1]+1);
      for j:=i-1 downto 1 do
        if h[j]>h[i] then break;
      g[i]:=max(g[i],f[j]+1);
    end;
    ans:=max(ans,max(f[i],g[i]));
  end;
  writeln(ans);
  close(input);close(output);
end.
