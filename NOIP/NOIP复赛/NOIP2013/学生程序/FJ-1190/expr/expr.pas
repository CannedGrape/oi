var
  a,c:array[-10..100020]of longint;
  b:array[-10..100020]of char;
  t,g:longint;
procedure re;
  var
    k,i,j:longint;
    ch:char;
  begin
  assign(input,'expr.in');
  reset(input);
    i:=0;
    repeat
      inc(i);
      repeat
        read(ch);
        if ord(ch)<48 then break;
        inc(j);
        a[i]:=a[i]*10+ord(ch)-48;
      until false;
      b[i]:=ch;
    until eoln;
    t:=i;
  close(input);
  end;
procedure ma;
  var
    s,i,j,d:longint;
  begin
    s:=0;
    c[0]:=0;
    for i:=1 to t-1 do
      if b[i]='+'then
        begin
          inc(s);
          c[s]:=i;
        end;
    inc(s);
    c[s]:=t;
    for i:=1 to s do
      begin
        d:=1;
        for j:=c[i-1]+1 to c[i] do
          d:=d*a[j] mod 10000;
        g:=g+d mod 10000;
      end;
  end;
procedure ou;
  begin
  assign(output,'expr.out');
  rewrite(output);
    writeln(g);
  close(output);
  end;
begin
  re;
  ma;
  ou;
end.
