var a,b:array[0..200001]of longint;
    x,a1,b1:longint;c:char;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
    a1:=0;a[1]:=0;b1:=0;b[0]:=0;
    while not eoln do
    begin
      read(c);
      if c in ['0'..'9'] then
      begin
        inc(a1);a[a1]:=0;
        while c in ['0'..'9'] do
        begin
          a[a1]:=(a[a1]*10+ord(c)-48) mod 10000;
          if eoln then break;read(c);
        end;
      end;
      if eoln then break;
      case c of
        '+':x:=1;
        '*':x:=2;
      end;
      while b[b1]>=x do
      begin
        case b[b1] of
          1:a[a1-1]:=(a[a1-1]+a[a1]) mod 10000;
          2:a[a1-1]:=(a[a1-1]*a[a1]) mod 10000;
        end;
        dec(a1);dec(b1);
      end;
      inc(b1);b[b1]:=x;
    end;
    while (b1>0)and(b[b1]>0) do
    begin
      case b[b1] of
        1:a[a1-1]:=(a[a1-1]+a[a1]) mod 10000;
        2:a[a1-1]:=(a[a1-1]*a[a1]) mod 10000;
      end;
      dec(a1);dec(b1);
    end;
    writeln(a[1]);
  close(input);close(output);
end.
