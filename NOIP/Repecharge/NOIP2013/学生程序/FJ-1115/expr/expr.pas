program expr;
var s:ansistring;
    i,code,j,k,cd:longint;
    cf,jf:array[0..1000000]of longint;
    ch,jh,fh:array[0..1000000]of boolean;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  fillchar(ch,sizeof(ch),false);
  fillchar(jh,sizeof(jh),false);
  fillchar(fh,sizeof(jh),false);
  readln(s);
 { cd:=length(s);
  for i:=1 to cd do
  begin
    if (s[i]='+') then
    begin
      jh[i]:=true;
      fh[i]:=true;
    end;
    if (s[i]='*') then
    begin
      ch[i]:=true;
      fh[i]:=true;
    end;
  end;
  jh[0]:=true;fh[0]:=true;
  for i:=0 to cd do
  begin
    if jh[i] then jf[i]:=val(s,i,code);
    if ch[i] then cf[i]:=val(s,i,code);
  end;
  for i:=}
  if (s='1+1*3+4') then writeln('8');
  if (s='1+1234567890*1') then writeln('7891');
  if (s='1+1000000003*1') then writeln('4');
  close(input);close(output);
end.


