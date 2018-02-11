var b,a:array[0..100000] of longint;
    t:int64;
    i,j,la,lb,x:longint;
    st,s:set of char;
    ch:char;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  s:=['0'..'9'];
  st:=['0'..'9','+','*'];
  repeat
    read(ch);
    if not (ch in st) then continue;
    if ch in s then t:=t*10+ord(ch)-48
    else
    begin
      if t<>0 then
      begin
        inc(la);
        a[la]:=t mod 10000;
        t:=0;
      end;
      if ch='+' then x:=11 else x:=21;
      while b[lb]>x do
      begin
        case b[lb] of
        11:a[la-1]:=(a[la-1]+a[la]) mod 10000;
        21:a[la-1]:=(a[la-1]*a[la]) mod 10000;
        end;
        dec(lb);
        dec(la);
      end;
      inc(lb);
      b[lb]:=x;
    end;
  until eof;
  if t>0 then
  begin
    inc(la);
    a[la]:=t mod 10000;
  end;
  while lb<>0 do
  begin
    case b[lb] of
    11:a[la-1]:=(a[la-1]+a[la]) mod 10000;
    21:a[la-1]:=(a[la-1]*a[la]) mod 10000;
    end;
    dec(lb);
    dec(la);
  end;
  writeln(a[1]);
  close(input);close(output);
end.
