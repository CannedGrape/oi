program expand;
var i,kk,p1,p2,p3:longint; s:ansistring;
    ch:char;
function sg(ch:char):longint;
begin
  sg:=0;
  if ch in ['0'..'9'] then sg:=2;
  if ch in ['a'..'z'] then sg:=1;
  if ch in ['A'..'Z'] then sg:=1;
end;   
function cha(ch:char):char;
begin
  if (p1=1) and ( ch in ['A'..'Z']) then begin cha:=chr(ord(ch)-ord('A')+ord('a')); exit; end;
  if (p1=2) and ( ch in ['a'..'z']) then begin cha:=chr(ord(ch)-ord('a')+ord('A')); exit; end;
  if p1 = 3 then cha:='*' else cha:=ch;
end;
begin
  assign(input,'expand.in'); reset(input);
  assign(output,'expand.out'); rewrite(output);
  readln(p1,p2,p3);
  readln(s);
  for i:=1 to length(s) do begin 
    if (i=1)or(i=length(s)) then begin 
      write(s[i]); continue;
    end;
    if (s[i]='-') and (sg(s[i-1])=sg(s[i+1])) and (sg(s[i+1])<>0) and (ord( s[i-1] )<ord( s[i+1]) ) then begin
      if p3=1 then begin
         for ch:=succ(s[i-1]) to pred(s[i+1]) do  for kk:=1 to p2 do 
           write(cha(ch));
      end
      else begin
         for ch:=pred(s[i+1]) downto succ(s[i-1])  do  for kk:=1 to p2 do 
           write(cha(ch));
      end;
    end else write(s[i]);
  end;
  writeln;
  close(input); close(output);
end.
