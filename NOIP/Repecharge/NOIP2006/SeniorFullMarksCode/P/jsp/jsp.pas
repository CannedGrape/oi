{
 Problem: Noip 2006 Problem 3
 Algorithm: Simulation
}
const
  maxn = 20;
  maxm = 20;
  maxs = 5000;
type
  Tseq = record
           st, ed:longint;
         end;
var
  n, m, i, j, k, ans:longint;
  ma, tim, x, y:longint;
  t:array[1..maxn] of longint;
  data, a:array[1..maxn*maxm] of longint;
  num:array[1..maxn,1..maxm] of longint;
  time:array[1..maxn,1..maxm] of longint;
  free:array[1..maxm,1..maxs] of Tseq;
  count:array[1..maxm] of longint;
  last:array[1..maxn] of longint;

function max(a, b:longint):longint;
begin
  if a > b then max:=a else max:=b;
end;

function find_free(k, ma, tim:longint; var x, y:longint):longint;
var
  i, minx, best:longint;
begin
  minx:=maxlongint;
  for i:=1 to count[ma] do
    if free[ma, i].ed - free[ma, i].st >= tim then
      if last[k] <= free[ma, i].st then
      begin
        if free[ma, i].st < minx then
        begin
          minx:=free[ma, i].st;
          best:=i;
        end;
      end else
      if (last[k] > free[ma, i].st) and (last[k] + tim <= free[ma, i].ed) then
      begin
        if last[k] < minx then
        begin
          minx:=last[k];
          best:=i;
        end;
      end;

  find_free:=best;
  x:=minx;
  y:=x + tim;
end;

begin
  assign(input,'jsp.in');
  reset(input);
  assign(output,'jsp.out');
  rewrite(output);

  { input }
  read(m, n);
  for i:=1 to m * n do read(data[i]);
  for i:=1 to n do
    for j:=1 to m do read(num[i, j]);
  for i:=1 to n do
    for j:=1 to m do read(time[i, j]);

  { Main }
  fillchar(t, sizeof(t), 0);
  for i:=1 to n * m do
  begin
    inc(t[data[i]]);
    a[i]:=t[data[i]];
  end;

  fillchar(last, sizeof(last), 0);
  for i:=1 to m do
  begin
    count[i]:=1;
    free[i, 1].st:=0;
    free[i, 1].ed:=maxlongint;
  end;

  for i:=1 to n * m do
  begin
    ma:=num[data[i], a[i]];
    tim:=time[data[i], a[i]];
    k:=find_free(data[i], ma, tim, x, y);

    inc(count[ma]);
    free[ma, count[ma]].st:=y;
    free[ma, count[ma]].ed:=free[ma, k].ed;
    free[ma, k].ed:=x;

    last[data[i]]:=y;
  end;

  { output }
  ans:=-1;
  for i:=1 to m do
    for j:=1 to count[i] do
      if free[i, j].ed = maxlongint then
        ans:=max(ans, free[i, j].st);
  writeln(ans);

  close(input);
  close(output);
end.
