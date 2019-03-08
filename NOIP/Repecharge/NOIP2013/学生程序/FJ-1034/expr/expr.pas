var
  s,a:ansistring;
  i,j,ls,la,lb,lz,c,tot:longint;
  work:array[1..100000]of longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  a:='';s:=s+' ';la:=0;
  while (s[1]<>' ')and(s[1]<>'+')and(s[1]<>'*')do
    begin
      inc(la);a:=a+s[1];delete(s,1,1);
    end;
  while (la>1)and(a[1]='0')do begin delete(a,1,1);dec(la);end;
  if la>4 then begin a:=copy(a,la-4+1,4);la:=4;end;
  c:=0;
  for i:=1 to la do c:=c*10+ord(a[i])-ord('0');
  lz:=1;work[lz]:=c;

  while s[1]<>' ' do
    begin

      if s[1]='+' then
        begin
          delete(s,1,1);
          la:=0;a:='';
          while (s[1]<>' ')and(s[1]<>'+')and(s[1]<>'*')do
            begin
              inc(la);a:=a+s[1];delete(s,1,1);
            end;
          while (la>1)and(a[1]='0')do begin delete(a,1,1);dec(la);end;
          if la>4 then begin a:=copy(a,la-4+1,4);la:=4;end;
          c:=0;
          for i:=1 to la do c:=c*10+ord(a[i])-ord('0');
          inc(lz);work[lz]:=c;
        end

      else if s[1]='*' then
        begin
          delete(s,1,1);
          la:=0;a:='';
          while (s[1]<>' ')and(s[1]<>'+')and(s[1]<>'*')do
            begin
              inc(la);a:=a+s[1];delete(s,1,1);
            end;
          while (la>1)and(a[1]='0')do begin delete(a,1,1);dec(la);end;
          if la>4 then begin a:=copy(a,la-4+1,4);la:=4;end;
          c:=0;
          for i:=1 to la do c:=c*10+ord(a[i])-ord('0');
          work[lz]:=work[lz]*c;
          work[lz]:=work[lz] mod 10000;
        end;

    end;
  tot:=0;
  for i:=1 to lz do begin tot:=tot+work[i];tot:=tot mod 10000;end;
  writeln(tot);
  close(input);
  close(output);
end.
