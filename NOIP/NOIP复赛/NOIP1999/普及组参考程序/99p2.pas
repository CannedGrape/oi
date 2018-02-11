const
  step:integer=0;
  chars:array[0..15] of char=('0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F');
var
  digit:array[char] of integer;
  i,n,g:integer;
  m,s:string;
  ok:boolean;
begin
  for i:=0 to 9 do digit[char(ord('0')+i)]:=i;
  for i:=0 to 5 do digit[char(ord('A')+i)]:=i+10;
  write('n=');  readln(n);
  write('m=');  readln(s);
  for i:=1 to length(s) do s[i]:=upcase(s[i]);
  repeat
    ok:=true;
    for i:=1 to length(s) div 2 do
      if s[i]<>s[length(s)+1-i] then ok:=false;
    if ok then break;
    inc(step);
    m:=s; g:=0;
    for i:=length(m) downto 1 do
    begin
      s[i]:=chars[(digit[m[i]]+digit[m[length(m)+1-i]]+g) mod n];
      g:=(digit[m[i]]+digit[m[length(m)+1-i]]+g) div n;
    end;
    if g>0 then s:=chars[g]+s;
  until step>=30;
  if ok then
    writeln('STEP=',step)
  else
    writeln('Impossible');
end.
