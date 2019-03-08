var i,j,l,la,x,t,k:longint;
    a,b:array[0..10]of longint;
    s:array[1..100000]of char;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
    while not eoln do
    begin
      inc(k);read(s[k]);
    end;
    l:=0;i:=0;s[k+1]:=')';
    while i<k+1 do
    begin
      inc(i);
      if s[i] in ['0'..'9'] then
        t:=(t*10+ord(s[i])-48) mod 10000
      else
      begin
        if t<>0 then
        begin inc(la);a[la]:=t mod 10000;t:=0;end;
        case s[i] of
          '+':x:=1;
          '*':x:=2;
          ')':x:=0;
        end;
        while x<=b[l] do
        begin
          case b[l] of
            1:a[l]:=(a[l]+a[la]) mod 10000;
            2:a[l]:=(a[l]*a[la]) mod 10000;
          end;
          dec(l);dec(la);
          if l<0 then break;
        end;
      end;
      if x>0 then
      begin
        inc(l);b[l]:=x;x:=0;
      end;
    end;
    write(a[1] mod 10000);
  close(input);close(output);
end.
