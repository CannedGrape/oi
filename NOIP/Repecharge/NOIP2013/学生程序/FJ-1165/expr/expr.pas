var
  a:array[1..100005] of longint;
  i,an,cn,k,j:longint;
  c:array[1..100005] of char;
  s:ansistring;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  read(s);
  an:=1;
  cn:=0;
  for i:=1 to length(s) do
    if (ord(s[i])>47) and (ord(s[i])<58) then a[an]:=a[an]*10+(ord(s[i])-48)
    else begin inc(cn); c[cn]:=s[i]; inc(an); end;

  for i:=1 to an do a[i]:=a[i] mod 10000;

  for i:=1 to cn do
    if c[i]='*' then
    begin
      if a[i] div 10000=0 then
      begin
        k:=(a[i]*a[i+1]) mod 10000;
        a[i]:=k;
        a[i+1]:=i*10000;
      end
      else
      begin
        k:=(a[ a[i] div 10000 ]*a[i+1]) mod 10000;
        a[ a[i] div 10000 ]:=k;
        a[i+1]:=(a[i] div 10000)*10000;
      end;
    end;
for j:=1 to cn-1 do
  for i:=1 to cn do
    if (c[i]='+') and (a[i+1] div 10000<>i) then
    begin
      if (a[i] div 10000=0) and (a[i+1] div 10000=0) then
      begin
        k:=(a[i]+a[i+1]) mod 10000;
        a[i]:=k;
        a[i+1]:=i*10000;
      end
      else
        if (a[i] div 10000=0) and (a[i+1] div 10000<>0) then
        begin
          k:=(a[ a[i+1] div 10000 ]+a[i]) mod 10000;
          a[ a[i+1] div 10000 ]:=k;
          a[i]:=(a[i+1] div 10000)*10000;
        end
        else
          if (a[i] div 10000<>0) and (a[i+1] div 10000=0) then
          begin
            k:=(a[ a[i] div 10000 ]+a[i+1]) mod 10000;
            a[ a[i] div 10000 ]:=k;
            a[i+1]:=(a[i] div 10000)*10000;
          end
          else
            if (a[i] div 10000<>0) and (a[i+1] div 10000<>0) and (a[i+1] div 10000<>a[i] div 10000) then
            begin
              k:=(a[ a[i] div 10000 ]+a[i+1] div 10000) mod 10000;
              a[ a[i] div 10000 ]:=k;
              a[ a[i+1] div 10000 ]:=(a[i] div 10000)*10000;
            end;
    end;
  writeln(a[1]);
  close(input);
  close(output);
end.
