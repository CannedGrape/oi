unit
  shanshan_lib;

interface

procedure init;
function show(s1, s2, s3:integer):integer;
procedure answer(x:integer);

implementation
var
  __initialized, __realTest : boolean;
  __x, __count : integer;
  log, fout : text;

procedure Error(msg: string; code : integer);
begin
	if __realTest then
  begin
    writeln(fout, code);
    close(fout);
	end
  else
    writeln(msg);
	halt(0);
end;

procedure init;
var
  s : string;
  f : text;
  code : integer;
begin
  if __initialized then
     Error('Already initialized.', 0);
  assign(f, 'shanshan.in');
  reset(f);
  readln(f, s);
  if s[1] = ':' then
  begin
    __realTest := true;
    delete(s, 1, 3);
    assign(fout, 'shanshan.out');
    rewrite(fout);
    end
  else begin
    assign(log, 'shanshan.log');
    rewrite(log);
  end;
  close(f);
  val(s, __x, code);
end;

function show(s1, s2, s3:integer):integer;
var
  ret, best : integer;
begin
  ret := 1;
  best := s1;
  if(s1 < 1)or(s1 > 1024)or(s2 < 1)or(s2 > 1024)or(s3 < 1)or(s3 > 1024) then
    Error('Error in parameters.', -2);
  if abs(s2 - __x) < abs(best - __x) then begin ret := 2; best := s2; end;
  if abs(s3 - __x) < abs(best - __x) then begin ret := 3; best := s3; end;
  inc(__count);
  if not __realTest then
    writeln(log, 'You called show(', s1, ', ', s2, ', ', s3, '). Return value = ', ret)
  else if __count > 5 then
    Error('Too many calls.', -3);
  show := ret;
end;

procedure answer(x:integer);
begin
  if not __realTest then
  begin
    writeln(log, 'Your answer is ', x, '. You called ', __count, ' times.');
    close(log);
  end else
  begin
    if x = __x then
      writeln(fout, __count)
    else
      Error('Wrong Answer.', -1);
      close(fout);
  end;
end;

begin
end.
