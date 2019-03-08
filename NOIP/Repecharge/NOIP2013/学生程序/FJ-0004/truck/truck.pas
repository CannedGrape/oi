const
  maxn = 10000;
  maxm = 50000;

type
  te = record
    u, v: integer;
    w: longint;
  end;

  pedge = ^tedge;
  tedge = record
    v: integer;
    w: longint;
    next: pedge;
  end;

var
  e: array[1..maxm] of te;
  pre: array[1..maxn] of longint;
  edge: array[1..maxn] of pedge;
  dist: array[1..maxn] of longint;
  stk, stk2: array[0..maxn] of integer;
  i, j, q, n: longint;
  m: longint;
  l, r: longint;

procedure qsort(l, r: integer);
var
  i, j: integer;
  t: te;
begin
  if l>=r then exit;
  i:=l;
  j:=r;
  t:=e[i];
  while i<j do begin
    while (i<j) and (t.w>=e[j].w) do dec(j);
    e[i]:=e[j];
    while (i<j) and (e[i].w>=t.w) do inc(i);
    e[j]:=e[i];
  end;
  e[i]:=t;
  qsort(l, i-1);
  qsort(i+1, r);
end;

function get(i: integer): integer;
begin
  if pre[i]<>i then pre[i]:=get(pre[i]);
  get:=pre[i];
end;

procedure road(u, v: integer; w: longint);
var
  p: pedge;
begin
  new(p);
  p^.v:=v;
  p^.w:=w;
  p^.next:=edge[u];
  edge[u]:=p;
end;

function min(a, b: longint): longint;
begin
  if a<=b then min:=a else min:=b
end;

procedure push(i, source: integer; distance: longint);
begin
  stk[r]:=i;
  stk2[r]:=source;
  dist[i]:=distance;
  inc(r);
end;

procedure expand;
var
  p: pedge;
begin
  p:=edge[stk[l]];
  while p<>nil do begin
    if p^.v<>stk2[l] then push(p^.v, stk[l], min(dist[stk[l]], p^.w));
    p:=p^.next;
  end;
end;

begin
  assign(input, 'truck.in');
  reset(input);
  readln(n, m);
  for i:=1 to m do
    with e[i] do readln(u, v, w);
  qsort(1, m);
  for i:=1 to n do begin
    pre[i]:=i;
    edge[i]:=nil;
  end;

  j:=0;
  for i:=1 to m do begin
    if j=n-1 then break;
    with e[i] do
      if get(u)<>get(v) then begin
        road(u, v, w);
        road(v, u, w);
        pre[pre[u]]:=v;
        inc(j);
      end;
  end;
  readln(q);

  assign(output, 'truck.out');
  rewrite(output);

  for q:=q downto 1 do begin
    readln(i, j);
    dist[j]:=-1;
    l:=0;
    r:=0;
    push(i, 0, 100000);
    while (l<r) and (dist[j]=-1) do begin
      expand;
      inc(l);
    end;
    writeln(dist[j]);
  end;

  close(input);
  close(output);
end.
