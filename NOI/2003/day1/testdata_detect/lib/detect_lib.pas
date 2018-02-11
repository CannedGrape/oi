unit detect_lib;

interface

procedure prog_initialize;
function ask_x(const x0: integer; var y1, y2: double): longint;
function ask_y(const y0: longint; var x1, x2: double): longint;
procedure ret_area(const s: double);
procedure ret_n(const n: longint);
procedure ret_vertex(const x, y: longint);

implementation

const
  maxn = 1000;
  maxc = 10000;
  minc = -10000;
  EpsReal = 1e-6;

var
  FInTest, FInitialized: boolean;
  n, ansstep, currans: longint;
  dx, dy: array [1..maxn] of longint;
  cx, cy: array [minc..maxc, 1..2] of double;
  minx, miny, maxx, maxy: longint;
  Score, anscount, Count: longint;

function IntToStr(const x: longint): string;
begin
  str(x, Result);
end;

function RealToStr(const x: double): string;
begin
  str(x:0:2, Result);
end;

procedure WriteLog(const ctg, msg: string);
var
  f: text;
begin
  if not FInTest then
  begin
    Assign(f, 'detect.log');
    Append(f);
    writeln(f, '[', ctg, '] ', msg);
    close(f);
  end;
end;

procedure Error(const msg: string);
begin
  WriteLog('ERR', msg);
  halt(1);
end;

function sgn(const x: longint): longint;
begin
  if x > 0 then Result := 1 else Result := -1;
end;

function encode(const s: string): string;
var
  i: longint;
begin
  Result := s;
  for i:=1 to length(s) do Result[i] := chr(ord(s[i]) xor $3f);
end;

procedure InitLog;
var
  F: Text;
begin
  Assign(F, 'detect.log');
  Rewrite(F);
  Close(F);
end;

procedure DoFinal(const Score: longint);
var
  F: Text;
begin
  WriteLog('CNT', 'Count = ' + IntToStr(Count));
  WriteLog('SCR', 'Score = ' + IntToStr(Score));

  if FInTest then
  begin
    Assign(F, 'detect.out');
    Rewrite(F);
    Writeln(F, Score);
    Close(F);
  end;
  halt;
end;

procedure prog_initialize;
const
  password = 'detect';
var
  F: Text;
  i, j, p, q: longint;
  check, finish: array [minc..maxc] of boolean;
  s: string;
begin
  if FInitialized then error('prog_initialize: Reinitialized!');

  Assign(F, 'detect.in');
  Reset(F);
  Read(F, n);

  if n < 0 then
  begin
    FInTest := true;
    n := (-n) xor $3F;
    if not seekeof(F) then readln(F, s);
    while s[length(s)] <= #32 do SetLength(s, length(s)-1);
    if Encode(s) <> password then error('Invalid format!');
    for i:=1 to n do read(F, dx[i], dy[i]);
    for i:=1 to n do dx[i] := dx[i] xor $3f3f3f3f;
    for i:=1 to n do dy[i] := dy[i] xor $3f3f3f3f;
    FInTest := true;
  end else
  begin
    for i:=1 to n do read(F, dx[i], dy[i]);
    FInTest := false;
    InitLog();
  end;

  minx := maxc; miny := maxc;
  maxx := minc; maxy := minc;

  for i:=1 to n do
  begin
    if dx[i] < minx then minx := dx[i];
    if dy[i] < miny then miny := dy[i];
    if dx[i] > maxx then maxx := dx[i];
    if dy[i] > maxy then maxy := dy[i];
  end;

  fillchar(check, sizeof(check), false);
  fillchar(finish, sizeof(finish), false);
  for i:=1 to n do
  begin
    p := dx[i mod n + 1] - dx[i];
    q := dy[i mod n + 1] - dy[i];
    for j:=0 to abs(p)-1 do
     if check[dx[i] + j * sgn(p)] then
     begin
       cy[dx[i] + j * sgn(p), 2] := dy[i] + q * j / abs(p);
       if finish[dx[i] + j * sgn(p)] then error('prog_initialize: Data file error!');
       finish[dx[i] + j * sgn(p)] := true;
     end else
     begin
       cy[dx[i] + j * sgn(p), 1] := dy[i] + q * j / abs(p);
       check[dx[i] + j * sgn(p)] := true;
     end;
  end;
  for i:=minx to maxx do if not finish[i] then cy[i, 2] := cy[i, 1];
  
  fillchar(check, sizeof(check), false);
  fillchar(finish, sizeof(finish), false);
  for i:=1 to n do
  begin
    p := dx[i mod n + 1] - dx[i];
    q := dy[i mod n + 1] - dy[i];
    for j:=0 to abs(q)-1 do
     if check[dy[i] + j * sgn(q)] then
     begin
       cx[dy[i] + j * sgn(q), 2] := dx[i] + p * j / abs(q);
       if finish[dy[i] + j * sgn(q)] then error('prog_initialize: Data file error!');
       finish[dy[i] + j * sgn(q)] := true;
     end else
     begin
       cx[dy[i] + j * sgn(q), 1] := dx[i] + p * j / abs(q);
       check[dy[i] + j * sgn(q)] := true;
     end;
  end;
  for i:=miny to maxy do if not finish[i] then cx[i, 2] := cx[i, 1];

  Close(F);

  ansstep := 0;
  Count := 0;

  WriteLog('INI', 'prog_initialize: OK, ' + IntToStr(n) + ' points read.');
  FInitialized := true;
end;

function ask_x(const x0: longint; var y1, y2: double): longint;
begin
  WriteLog('MSG', 'ask_x: Called with x0 = ' + IntToStr(x0) + '.');
  if not FInitialized then Error('ask_x: Not initialized!');

  inc(Count);
  if (x0 < minx) or (x0 > maxx) then
  begin
    Result := 0;
    WriteLog('RET', 'ask_x: Returned 0.');
  end else
  begin
    y1 := cy[x0, 1];
    y2 := cy[x0, 2];
    if abs(cy[x0, 1] - cy[x0, 2]) < EpsReal then Result := 1 else Result := 2;
    WriteLog('RET', 'ask_x: Returned ' + IntToStr(Result) + ' with y1 =  ' + RealToStr(y1) + ' and y2 = ' + RealToStr(y2) +  '.');
  end;
end;

function ask_y(const y0: longint; var x1, x2: double): longint;
begin
  WriteLog('MSG', 'ask_y: Called with y0 = ' + IntToStr(y0) + '.');
  if not FInitialized then Error('ask_y: Not initialized!');

  inc(Count);
  if (y0 < miny) or (y0 > maxy) then
  begin
    Result := 0;
    WriteLog('RET', 'ask_y: Returned 0.');
  end else
  begin
    x1 := cx[y0, 1];
    x2 := cx[y0, 2];
    if abs(cx[y0, 1] - cx[y0, 1]) < EpsReal then Result := 1 else Result := 2;
    WriteLog('RET', 'ask_y: Returned ' + IntToStr(Result) + ' with x1 =  ' + RealToStr(x1) + ' and x2 = ' + RealToStr(x2) +  '.');
  end;
end;

procedure ret_area(const s: double);
const
  EpsReal = 1e-5;
var
  i: longint;
  t: double;
begin
  WriteLog('MSG', 'ret_area: Called with s = ' + RealToStr(s) + '.');

  if not FInitialized then Error('ret_area: Not initialized!');
  if ansstep <> 0 then Error('ret_area: Please answer step by step!');

  t := 0;
  for i:=1 to n do t := t + dx[i] * (dy[i mod n + 1] - dy[(i + n - 2) mod n + 1]);
  if abs(abs(t) - 2 * s) < EpsReal then
  begin
    inc(Score, 2);
    WriteLog('ANS', 'ret_area: Area right!');
  end else WriteLog('ANS', 'ret_area: Area not right!');
  inc(ansstep);
end;

procedure ret_n(const n: longint);
begin
  WriteLog('MSG', 'ret_n: Called with n = ' + IntToStr(n) + '.');

  if not FInitialized then Error('ret_n: Not initialized!');
  if ansstep <> 1 then Error('ret_n: Please answer step by step!');

  if n <> detect_lib.n then
  begin
    WriteLog('ANS', 'ret_n: Answer n not right!');
    DoFinal(Score);
  end else WriteLog('ANS', 'ret_n: Answer n right!');
  inc(ansstep);
  inc(Score, 1);
end;

procedure ret_vertex(const x, y: longint);
var
  i: longint;
begin
  WriteLog('MSG', 'ret_vertex: Called with x = ' + IntToStr(x) + ', y = ' + IntToStr(y) + '.');

  if not FInitialized then Error('ret_vertex: Not initialized!');
  if ansstep < 2 then Error('ret_vertex: Please answer step by step!');
  
  if ansstep = 2 then
  begin
    currans := -1;
    anscount := 1;
    for i:=1 to n do
     if (dx[i] = x) and (dy[i] = y) then
     begin
       currans := i;
       break;
     end;
    if currans = -1 then
    begin
      WriteLog('ANS', 'ret_vertex: First point not found!');
      DoFinal(Score);
    end else WriteLog('ANS', 'ret_vertex: First point found!');
    inc(ansstep);
  end else
  if ansstep = 3 then
  begin
    currans := currans mod n + 1;
    inc(anscount);
    if (dx[currans] = x) and (dy[currans] = y) then
    begin
      WriteLog('ANS', 'ret_vertex: Answer point right!');
      if anscount = n then
      begin
        inc(Score, 2);
        WriteLog('ANS', 'ret_vertex: All finished!');
        if Count < 700 then inc(Score, 5) else inc(Score, Trunc(5 * exp(-0.4*Sqr((700-Count)/700))));
        DoFinal(Score);
      end;
    end else
    begin
      WriteLog('ANS', 'ret_vertex: Answer point not right!');
      DoFinal(Score);
    end;
  end else Error('ret_vertex: Internal error!');
end;

begin
  FInitialized := false;
end.

