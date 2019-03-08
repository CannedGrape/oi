const
  maxn = 100000;
  reminder = 99999997;

var
  a, b, c: array[1..maxn] of longint;
  i, n, ans: longint;

procedure qsort(l, r: longint);
var
  i, j: longint;
  t, tb: longint;
begin
  if l>=r then exit;
  i:=l;
  j:=r;
  t:=a[l];
  tb:=b[l];
  while i<j do begin
    while (i<j) and (t<=a[j]) do dec(j);
    a[i]:=a[j];
    b[i]:=b[j];
    while (i<j) and (a[i]<=t) do inc(i);
    a[j]:=a[i];
    b[j]:=b[i];
  end;
  a[i]:=t;
  b[i]:=tb;
  qsort(l, i-1);
  qsort(i+1, r);
end;

function mergesort(l, r: longint): longint;
var
  i, j, k, m, ans: longint;
begin
	if l>=r then begin
    mergesort:=0;
  	exit;
  end;
  m:=(l+r) shr 1;
  ans:=(mergesort(l, m) + mergesort(m+1, r)) mod reminder;
  i:=l;
  j:=m+1;
  k:=l;
  while (i<=m) and (j<=r) do begin
    if b[i]<=b[j] then begin
      ans:=(ans+j-m-1) mod reminder;
      c[k]:=b[i];
      inc(i);
  	end
  	else begin
      c[k]:=b[j];
      inc(j);
    end;
    inc(k);
	end;
  if j>r then begin
    j:=m;
    i:=r-m;
    for r:=r downto k do begin
      ans:=(ans+i) mod reminder;
      b[r]:=b[j];
      dec(j);
    end;
  end;
 for i:=l to k-1 do b[i]:=c[i];
 mergesort:=ans;
end;

begin
  assign(input, 'match.in');
	reset(input);
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  close(input);

  qsort(1, n);
  ans:=mergesort(1, n);

  assign(output, 'match.out');
  rewrite(output);
  writeln(ans);
  close(output);
end.