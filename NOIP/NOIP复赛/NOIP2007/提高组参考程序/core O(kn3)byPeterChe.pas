program core;
const
  maxn = 65536;

var
  n, s, i, j, aa, bb, k, temp, st, en, ans, tou, max, len, dep, now: longint;
  w, f, mid: array[0..5000, 0..5000] of longint;
  p: array[0..50000, 1..2] of integer;
  a: array[0..5000] of integer;  
  d: array[0..5000] of longint;  
  
begin
assign(input, 'core.in');
assign(output, 'core.out');
reset(input);
rewrite(output);
  readln(n, s);
  for i := 1 to n do begin
    w[i, i] := 0;
	f[i, i] := 0;
    for j := i+1 to n do begin
	  f[i, j] := maxn;
	  f[j, i] := maxn;
	  w[i, j] := maxn;
	  w[j, i] := maxn;
	end;
  end;
  for i := 2 to n do begin
    read(aa, bb);
	readln(w[aa, bb]);
	w[bb, aa] := w[aa, bb];
	f[aa, bb] := w[aa, bb];
	f[bb, aa] := w[aa, bb];
  end;
  for k := 1 to n do begin
    for i := 1 to n do begin
	  for j := 1 to n do begin
	    if f[i, j] > f[i, k] + f[k, j] then f[i, j] := f[i, k] + f[k, j];
	  end;
	end;
  end;
  fillchar(p, sizeof(p), 0);
  tou := 0;
  max := 0;
  for i := 1 to n-1 do begin
    for j := i+1 to n do begin
	  if f[i, j] > max then begin
	    p[1, 1] := i;
		p[1, 2] := j;
		tou := 1;
		max := f[i, j];
	  end else begin
	    if f[i, j] = max then begin
		  inc(tou);
		  p[tou, 1] := i;
		  p[tou, 2] := j;
		end;
	  end;
	end;
  end;
  ans := maxn;
  for dep := 1 to tou do begin
    len := 0;
	st := p[dep, 1];
	en := p[dep, 2];
	now := en;
	while f[now, st] <> w[now, st] do begin
	  for k := 1 to n do begin
	    if (f[st, now] = f[st, k] + w[k, now]) and (k <> now) then begin
		  inc(len);
		  a[len] := now;
		  now := k;
		  break;
		end;
	  end;
	end;
	inc(len);
	a[len] := now;
	inc(len);
	a[len] := st;
	for i := 1 to len do begin
	  temp := 0;
	  st := a[i];
	  for k := 1 to n do begin
	    d[k] := f[st, k];
	  end;
	  for j := i+1 to len do begin
	    en := a[j];
	    if f[st, en] > s then break;
		for k := 1 to n do begin
		  if d[k] > f[k, en] then d[k] := f[k, en];
		end;
	  end;
	  for k := n downto 1 do begin
	    if d[k] > temp then begin
		  temp := d[k];
		  if temp >= ans then break;
		end;
	  end;
	  if temp < ans then ans := temp;
	end;
  end;
  writeln(ans);
close(input);
close(output);
end.
