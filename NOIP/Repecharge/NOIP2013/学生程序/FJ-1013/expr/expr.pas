program expr;
var
  c:char;
  a,b:longint;
  s,t:array[0..10000] of longint;
procedure ja;
  begin
    s[0]:=s[0]-1;
    t[0]:=t[0]-1;
    s[s[0]]:=(s[s[0]]+s[s[0]+1]) mod 10000;
  end;
procedure ca;
  begin
    s[0]:=s[0]-1;
    t[0]:=t[0]-1;
    s[s[0]]:=(s[s[0]]*s[s[0]+1]) mod 10000;
  end;
procedure jin;
  begin
    s[0]:=s[0]+1;
    s[s[0]]:=a;
    a:=0
  end;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  while not eoln do
  begin
    read(c);
    if c='+' then
    begin
      while (t[0]<>0) do
        if (t[t[0]]=1) then ja
          else ca;
      jin;
      inc(t[0]);
      t[t[0]]:=1;
    end
    else
      if c='*' then
      begin
        while (t[0]<>0) and (t[t[0]]=1) do ca;
        jin;
        inc(t[0]);
        t[t[0]]:=2;
      end
      else
      if (ord(c)>47) and (ord(c)<58) then
      begin
        a:=a*10;
        a:=a+ord(c)-48;
        a:=a mod 10000;
      end;
  end;
  jin;
  while (t[0]<>0) do
    if (t[t[0]]=1) then ja
      else ca;
  writeln(s[1]);
  close(input);
  close(output);
end.







