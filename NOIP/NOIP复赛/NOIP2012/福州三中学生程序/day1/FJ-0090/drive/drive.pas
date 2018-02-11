const
  maxn = 10;//100000;
type
  tab = record
    a: longint;
    b: longint;
  end;
var
  a, b, h: array[0..maxn] of longint;
  i, j, k, p, q, m, n: longint;
  x0: longint;
  ans, anss: longint;
  value: tab;

function mydiv(a, b: longint): longint;
begin
  if b=0 then mydiv:=2000000001
  else mydiv:=a div b
end;

function test(k: longint; x: longint; method: char): tab;
var
  ret: tab;
begin
  ret.a:=0;
  ret.b:=0;
  if (method='b') and (b[i]<>0) and (x-abs(h[i]-h[b[i]])>=0) then begin
    ret:=test(b[i], x-abs(h[i]-h[b[i]]), 'a');
    ret.b:=ret.b+abs(h[i]-h[b[i]]);
  end else if (method='a') and (a[i]<>0) and (x-abs(h[i]-h[a[i]])>=0) then begin
    ret:=test(a[i], x-abs(h[i]-h[a[i]]), 'b');
    ret.a:=ret.a+abs(h[i]-h[a[i]]);
  end;
  test:=ret;
end;

begin
assign(input, 'drive.in');
assign(output, 'drive.out');
reset(input);
rewrite(output);
  readln(n);
  h[0]:=-1000000001;
  for i:=1 to n do read(h[i]);
  fillchar(a, sizeof(a), 0);
  b[n]:=0;
  a[n]:=0;
  b[n-1]:=n;
  a[n-1]:=0;
  for i:=1 to n-2 do begin
    b[i]:=i+1;
    for j:=i+1 to n do
      if abs(h[j]-h[i])<abs(h[b[i]]-h[i]) then b[i]:=j
      else if (abs(h[j]-h[i])<abs(h[a[i]]-h[i]))
           or ((abs(h[j]-h[i])=abs(h[a[i]]-h[i])) and (h[j]<h[i])) then a[i]:=j;
  end;
  readln(x0);
  ans:=1000000001;
  anss:=0;
  for i:=1 to n do begin
    value:=test(i, x0, 'a');
    if (mydiv(value.a, value.b)<ans) or ((mydiv(value.a, value.b)=ans) and (h[i]>h[anss])) then begin
      ans:=value.a div value.b;
      anss:=i;
    end;
  end;
  writeln(anss-1);
  readln(m);
  for i:=1 to m do begin
    readln(value.a, value.b);
    value:=test(value.a, value.b, 'a');
    writeln(value.a, ' ', value.b);
  end;
close(input);
close(output);
end.
