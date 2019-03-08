label fuck;
const
  maxn = 131071;
var
  a: array[0..maxn shl 1+1] of longint;
  i, m, n: longint;
  d, s, t: longint;

function min(a, b: longint): longint;
begin
  if a<=b then min:=a
  else min:=b
end;

procedure insert(p: longint; b: longint);
var
  temp: longint;
begin
  a[p]:=a[p]+b;
  repeat
    temp:=min(a[p], a[p xor 1]);
    inc(a[p shr 1], temp);
    dec(a[p], temp);
    dec(a[p xor 1], temp);
    p:=p shr 1;
  until p=1;
end;

function change(p, r: longint; b: longint): boolean;
begin
  change:=false;
  p:=p-1;
  r:=r+1;
  while p xor r<>1 do begin
    if not odd(p) then insert(p+1, b);
    if odd(r) then insert(r-1, b);
    if (a[p+1]<0) or (a[r-1]<0) then begin
      change:=true;
    end;
    p:=p shr 1;
    r:=r shr 1;
  end;
end;

begin
assign(input, 'classroom.in');
assign(output, 'classroom.out');
reset(input);
rewrite(output);
  readln(n, m);
  fillchar(a, sizeof(a), 0);
  for i:=1+maxn to n+maxn do begin
    read(d);
    insert(i, d);
  end;
  for i:=1 to m do begin
    readln(d, s, t);
    if change(s+maxn, t+maxn, -d) then begin
      writeln(-1);
      writeln(i);
      goto fuck;
    end;
  end;
  writeln(0);
fuck:
close(input);
close(output);
end.