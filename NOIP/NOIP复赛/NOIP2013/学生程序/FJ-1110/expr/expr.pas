program Project1;
var ch:char; i,sum:longint;
  a:array[1..1000] of longint;
begin
  assign(input,'number.in');  assign(output,'number.out');
  reset(input);rewrite(output);
  read(ch);   if ch='*' then begin writeln('0'); exit; end;
  val(ch,a[1]); i:=1;  sum:=0;
  while not eoln do
  begin
    read(ch);
    if ch='+' then sum:=sum+a[i];
    if (ch<>'+') and (ch<>'*') then begin i:=i+1;  val(ch,a[i]); end;
  end;
  sum:=sum+a[i];
  writeln(sum);
  close(input);close(output);
end.