program expr;
var
  s:ansistring;
  function se(st:ansistring):integer;
  var
    s1,s2:ansistring;
    i,r:longint;
    f:boolean;
  begin
    se:=0;
    r:=0;
    i:=0;
    f:=false;
    for i:=length(st)-1 downto 2 do
    if st[i]='+' then begin
    s1:=copy(st,1,i-1);
    s2:=copy(st,i+1,length(st)-i);
    r:=se(s1)+se(s2);
    f:=true;
    break;
    end;
    if not(f) then begin
    f:=false;
    for i:=length(st)-1 downto 2 do
    if st[i]='*' then begin
    s1:=copy(st,1,i-1);
    s2:=copy(st,i+1,length(st)-i);
    r:=se(s1)*se(s2);
    f:=true;
    break;
    end;
    end;
    if not(f) then val(st,r);
    se:=r mod 10000;
  end;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  writeln(se(s));
  close(input);
  close(output);
end.