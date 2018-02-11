program vigenere;

const maxn=10005;

var s:string;
    f:array[0..maxn] of boolean;
    a,b:array[0..maxn] of longint;
    t,h,now,len:longint;
    ss:ansistring;


procedure openf;
begin
  assign(input,'vigenere.in');
  assign(output,'vigenere.out');
  reset(input);
  rewrite(output);
end;

procedure closef;
begin
  close(input);
  close(output);
end;

procedure init;
var i,j:longint;
begin
  readln(s);
  len:=length(s);
  for i:=1 to len do
    if ord(s[i])>=ord('a') then
      a[i]:=ord(s[i])-ord('a')
    else
      a[i]:=ord(s[i])-ord('A');
end;

procedure main;
var i,j:longint;
    ch:char;
begin
  h:=0;
  fillchar(f,sizeof(f),false);
  read(ch);t:=0;
  while ((65<=ord(ch)) and (ord(ch)<=90))
  or ((97<=ord(ch)) and (ord(ch)<=122))do
    begin
      inc(h);inc(t);
      if h>len then h:=1;
      if ord(ch)>=ord('a') then
        now:=ord(ch)-ord('a')+1
      else
        begin
          now:=ord(ch)-ord('A')+1;
          f[t]:=true;
        end;
      b[t]:=now-a[h];
      if b[t]<1 then b[t]:=b[t]+26;
      read(ch);
    end;
end;

procedure print;
var i,j:longint;
begin
  for i:=1 to t  do
    if f[i] then
      write(chr(b[i]+ord('A')-1))
    else
      write(chr(b[i]+ord('a')-1));
end;

begin
  openf;
  init;
  main;
  print;
  closef;
end.

