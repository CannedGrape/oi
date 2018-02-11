const
  maxn=1000;
var
  l, r: array[0..maxn] of longint;
  i, n: longint;
  border: longint;

function min(a, b: longint): longint;
begin
  if a<=b then min:=a
  else min:=b
end;

function max(a, b: longint): longint;
begin
  if a>=b then max:=a
  else max:=b
end;

function fmax: longint;
var
  i, temp: longint;
  ans: longint;
begin
  ans:=0;
  temp:=l[0];
  for i:=1 to n-1 do begin
    ans:=max(ans, temp div r[i]);
    temp:=temp*l[i];
  end;
  ans:=max(ans, temp div r[n]);
  fmax:=ans;
end;

procedure swap(i, j: longint);
var
  tmpl, tmpr: longint;
begin
  tmpl:=l[i];
  tmpr:=r[i];
  l[i]:=l[j];
  r[i]:=r[j];
  l[j]:=tmpl;
  r[j]:=tmpr;
end;

procedure sortl(head, tail: longint);
var
  i, j: longint;
begin
  if head>=tail then exit;
  j:=tail+1;
  i:=head+1;
  while i<j do
    if l[i]<=l[head] then inc(i)
    else begin
      dec(j);
      swap(i,j);
    end;
  dec(i);
  swap(head, i);
  sortl(head, i-1);
  sortl(i+1, tail);
end;

procedure sortr(head, tail: longint);
var
  i, j: longint;
begin
  if head>=tail then exit;
  j:=tail+1;
  i:=head+1;
  while i<j do
    if r[i]<=r[head] then inc(i)
    else begin
      dec(j);
      swap(i,j);
    end;
  dec(i);
  swap(head, i);
  sortr(head, i-1);
  sortr(i+1, tail);
end;

procedure design(k, left, largest: longint);
var
  i: longint;
begin
  if k>=n then
    border:=min(border, max(largest, left div r[k]))
  else
    for i:=k to n do
      if left div r[i]<=border then begin
        swap(k, i);
        design(k+1, left*l[k], max(largest, left div r[k]));
        swap(k, i);
      end;
end;

begin

assign(input, 'game.in');
reset(input);
  readln(n);
  for i:=0 to n do readln(l[i], r[i]);
close(input);

  sortl(1, n);
  border:=fmax;
  sortr(1, n);
  design(1, l[0], 0);

assign(output, 'game.out');
rewrite(output);
  writeln(border);

close(output);
end.
