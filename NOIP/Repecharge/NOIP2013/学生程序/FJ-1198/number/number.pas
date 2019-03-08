var
  n,p,i:longint;
  g:boolean;
  a,f,sco:array[0..10000] of longint;
function max(x,y:longint):longint;
begin
  if x>y then max:=x
  else max:=y;
end;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
  read(a[i]);
  f[1]:=a[1];
  for i:=2 to n do
    f[i]:=max(max(f[i-1],f[i-1]+a[i]),a[i]);

  sco[0]:=f[1];
  for i:=1 to n do
  sco[i]:=max(sco[i-1]+f[i-1],sco[i-1]);
  if sco[n]<0 then begin sco[n]:=0-sco[n];g:=false;end
  else g:=true;
  sco[n]:=sco[n] mod p;
  if g=false then write('-');
  writeln(sco[n]);
  close(input);close(output);
end.
