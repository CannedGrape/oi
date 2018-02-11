program expr;
var
  i,j,k,ans:longint;
  ch:char;
  flag:boolean;
  num:array[1..100000] of longint;
procedure renu;
var i,j:longint;
begin
  repeat
    read(ch);
    if (ch<>'+') and (ch<>'*') then
      num[k]:=(num[k]*10+ord(ch)-ord('0')) mod 10000;
  until (ch='+') or (ch='*') or eof;
end;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  k:=0;
  flag:=false;
  repeat
    k:=k+1;
    renu;
    if flag then
      begin
        k:=k-1;
        num[k]:=(num[k]*num[k+1]) mod 10000;
        num[k+1]:=0;
        flag:=false;
      end;
    if ch='*' then
      flag:=true;
  until eof;
  ans:=0;
  for i:=1 to k do
    ans:=(ans+num[i]) mod 10000;
  writeln(ans);
  close(input);close(output);
end.
