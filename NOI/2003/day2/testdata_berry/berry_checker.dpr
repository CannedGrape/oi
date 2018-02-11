program berry_checker;
{$APPTYPE CONSOLE}
uses SysUtils;

const
  maxn = 10000;
  maxm = maxn * 10;

var
  inFile, outFile: text;
  n, m, k, i, j, p, tot, nn: integer;
  ans, cans, minans: integer;
  v, head, c: array [1..maxn] of integer;
  e, next: array [1..maxm] of integer;
  check, curr, cnow: array [1..maxn] of boolean;

procedure error(const msg: string);
begin
  writeln(msg);
  close(inFile);
  close(outFile);
  halt(1);
end;

function depth(dep, x: integer): boolean;
var
  i: integer;
begin
  Result := false;
  if check[x] then exit;
  cnow[x] := true;
  inc(nn);
  i := head[x];
  inc(cans, v[x]);
  while i <> 0 do
  begin
    if not cnow[e[i]] and curr[e[i]] then
     if not depth(dep+1, e[i]) then exit;
    i := next[i];
  end;
  Result := true;
end;

begin
  if ParamCount() <> 2 then
  begin
    writeln('checker format: ');
    writeln('  ' + ParamStr(0) + ' <input_file_name> <output_file_name>');
    halt(1);
  end;
  assign(inFile, ParamStr(1));
  assign(outFile, ParamStr(2));
  reset(inFile); reset(outFile);
  read(inFile, n, m, k);
  for i:=1 to n do read(inFile, j, v[j]);
  fillchar(head, sizeof(head), 0);
  for p:=1 to m do
  begin
    read(inFile, i, j);
    e[2*p-1] := j;
    next[2*p-1] := head[i];
    head[i] := 2*p-1;
    e[2*p] := i;
    next[2*p] := head[j];
    head[j] := 2*p;
  end;

  read(outFile, ans);
  fillchar(check, sizeof(check), false);
  tot := 0;
  cans := 0;
  minans := maxlongint;
  for i:=1 to k do
  begin
    read(outFile, p);
    inc(tot, p);
    for j:=1 to p do read(outFile, c[j]);
    fillchar(curr, sizeof(curr), false);
    for j:=1 to p do curr[c[j]] := true;
    nn := 0;
    fillchar(cnow, sizeof(cnow), false);
    cans := 0;
    if not depth(1, c[1]) then error('duplicate');
    if nn <> p then error('not connect');
    for j:=1 to n do check[j] := check[j] or cnow[j];
    cans := 0;
    for j:=1 to p do inc(cans, v[c[j]]);
    if cans < minans then minans := cans;
  end;

  if not seekeof(outFile) then error('extra');
  if tot <> n then error('lack');
  if minans <> ans then error('answer not match');

  writeln('Yes');

  close(inFile); close(outFile);
end.
