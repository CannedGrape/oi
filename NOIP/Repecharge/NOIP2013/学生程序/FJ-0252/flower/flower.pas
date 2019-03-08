program flower;
uses
  math;
type
  arr=array[1..100000]of longint;

var
  flo,rec:arr;
  input,output:text;
  i,n,m,recn,temp:longint;

procedure freopen;
begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
end;

procedure freclose;
begin
  close(input);
  close(output);
end;

procedure delete(a:arr;x:longint);
var
  i:longint;
begin
  for i:=x to n do
    a[i]:=a[i+1];
end;

function flag(a:arr;k:longint):boolean;
var
  f:integer;
begin
  flag:=false;
  f:=k mod 2;
  f:=f*(-2)+1;
  if (f*a[k]>f*a[k+1])and(f*a[k]>f*a[k-1]) then
    flag:=true;
end;

begin
  freopen;
  read(input,n);
  recn:=n;
  m:=1;
  for i:=1 to n do
    begin
      read(input,flo[i]);
      rec[i]:=flo[i];
    end;
//-------------------------------------
  repeat
    while (not flag(flo,m)) do
      begin
        delete(flo,m);
        dec(n);
        if n<0 then break;
      end;
    inc(m);
  until m>=n;
  temp:=recn;
  recn:=n;
  n:=temp;
//----------------------------------------
  m:=1;
  repeat
    while (flag(rec,m))or((rec[m]=rec[m+1])and(rec[m]=rec[m+1])) do
      begin
        delete(rec,m);
        dec(n);
        if n<0 then break;
      end;
    inc(m);
  until m>=n;
//-----------------------------------------
  if recn>n then write(output,recn)
  else write(output,n);
  freclose;
end.
