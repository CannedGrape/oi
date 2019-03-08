var i,j,n,m,ans,ans1,ans2:longint;
    input,output:text;
    a,b:array[1..100000]of longint;
function max(a,b:longint):longint;
begin
  if a>=b then max:=a else max:=b;
end;
procedure shanchu(x:longint);
var i,j,k:longint;
begin
  for i:=x to m-1 do
  a[i]:=a[i+1];
  dec(m);
end;
procedure search1(t:longint);
var i,j,k,x:longint;p:boolean;
begin
  if m=2 then begin ans:=max(ans,m); exit; end;
  x:=2; p:=true;
  while (x<=m) and (p=true) do begin
  if x+1<=m then if (a[x]>a[x-1]) and (a[x]>a[x+1]) then x:=x+2 else p:=false
  else if a[x]>a[x-1] then x:=x+2 else p:=false; end;
  if p then begin ans:=max(ans,m); exit; end;
  for i:=1 to m do begin
    if (i mod 2=0) and (i<>m) then
    if (a[i]<a[i-1]) or (a[i]<a[i+1]) then begin shanchu(i); break; end;
    if (i mod 2=0) and (i=m) and (a[i]<a[i-1]) then begin shanchu(i); break end;
  end;
  search1(t+1);
end;
procedure search2(t:longint);
var i,j,k,x:longint;p:boolean;
begin
  if m=2 then begin ans:=max(ans,m); exit; end;
  x:=2; p:=true;
  while (x<=m) and (p=true) do begin
  if x+1<=m then if (a[x]<=a[x-1]) and (a[x]<=a[x+1]) then x:=x+2 else p:=false
  else if a[x]<=a[x-1] then x:=x+2 else p:=false; end;
  if p then begin ans:=max(ans,m); exit; end;
  for i:=1 to m-1 do begin
    if (i mod 2=0) and (i<>m) then
    if (a[i]>=a[i-1]) or (a[i]>=a[i+1]) then begin shanchu(i); break; end;
    if (m mod 2=0) and (i=m) and (a[m]>=a[m-1]) then begin shanchu(m); break end;
  end;
  search2(t+1);
end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(input,n);
  for i:=1 to n do begin
  read(input,a[i]); b[i]:=a[i];
  end;
  m:=n;
  search1(1);
  m:=n;a:=b;
  search2(1);
  writeln(output,ans);
  close(input);close(output);
end.
