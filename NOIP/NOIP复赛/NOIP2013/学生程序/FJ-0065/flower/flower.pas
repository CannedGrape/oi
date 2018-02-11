var f:array[0..100000,0..1]of longint;
    i,j,k,n,m,ans:longint;
    h:array[0..100000]of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
  readln(n); ans:=1;
  for i:=1 to n do read(h[i]);
  for i:=1 to n do
   begin
    f[i,0]:=-111111111;
    f[i,1]:=-111111111;
   end;
  h[0]:=maxlongint;
  for i:=1 to n do
   for j:=0 to i-1 do
    begin
      if h[i]>h[j] then
       begin
         f[i,0]:=max(f[i,0],f[j,1]+1);
       end else
      if h[i]<h[j] then
       begin
         f[i,1]:=max(f[i,1],f[j,0]+1);
       end;
      if f[i,0]>ans then ans:=f[i,0];
      if f[i,1]>ans then ans:=f[i,1];
    end;
  for i:=1 to n do
   begin
    f[i,0]:=-111111111;
    f[i,1]:=-111111111;
   end;
   h[0]:=-maxlongint;
  for i:=1 to n do
   for j:=0 to i-1 do
    begin
      if h[i]>h[j] then
       begin
         f[i,0]:=max(f[i,0],f[j,1]+1);
       end else
      if h[i]<h[j] then
       begin
         f[i,1]:=max(f[i,1],f[j,0]+1);
       end;
      if f[i,0]>ans then ans:=f[i,0];
      if f[i,1]>ans then ans:=f[i,1];
    end;
  writeln(ans);
  close(input); close(output);
end.
