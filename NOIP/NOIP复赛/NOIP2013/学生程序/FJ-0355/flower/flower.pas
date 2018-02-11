Program mxpiii;
Var
   f:array[0..100000,0..1] of longint;
   h:array[0..100000] of longint;
   n,i,j,ans:longint;

Function max(x,y:longint):longint;
Begin
   if x>y then exit(x) else exit(y);
End;

Begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      read(h[i]);
      f[i][1]:=1; f[i][0]:=1;
    end;
  ans:=1;
  for i:=2 to n do
    for j:=1 to i-1 do
      begin
        if h[j]>h[i] then f[i][0]:=max(f[i][0],f[j][1]+1);
        if h[j]<h[i] then f[i][1]:=max(f[i][1],f[j][0]+1);
        ans:=max(ans,f[i][0]);
        ans:=max(ans,f[i][1]);
      end;
  writeln(ans);
  close(input);
  close(output);
End.