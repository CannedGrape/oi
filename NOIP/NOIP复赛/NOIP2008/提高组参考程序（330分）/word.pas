program word;
const
  maxn=100;

var
  st:string;
  a:array ['a'..'z'] of longint;
  n,max,min:longint;

procedure fileon;
begin
  assign(input,'word.in');
  assign(output,'word.out');
  reset(input);
  rewrite(output);
end;

procedure fileoff;
begin
  close(input);
  close(output);
end;

procedure scan;
begin
  readln(st);
  n:=length(st);
end;

procedure print;
var
  i,t:longint;
  flag:boolean;
begin
  t:=max-min;
  flag:=true;
  if (t=1) or (t=0) then
    flag:=false;
  for i:=2 to t-1 do
    if t mod i =0 then
      begin
        flag:=false;
        break;
      end;
  if flag then
    begin
      writeln('Lucky Word');
      writeln(t);
    end
  else
    begin
      writeln('No Answer');
      writeln(0);
    end;
end;

procedure main;
var
  i:longint;
  c:char;
begin
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    inc(a[st[i]]);
  max:=0;
  min:=1000;
  for c:='a' to 'z' do
    if a[c]<>0 then
      begin
        if a[c]>max then
          max:=a[c];
        if a[c]<min then
          min:=a[c];
      end;
end;

begin
  fileon;
  scan;
  main;
  print;
  fileoff;
end.
