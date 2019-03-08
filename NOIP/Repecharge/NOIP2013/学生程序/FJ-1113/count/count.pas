var
  n,x:char;
  ans:longint;
  a:array[1..8]of char;
  o,i,p:byte;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  fillchar(a,sizeof(a),'0');
  read(n); o:=0;  ans:=0;
  while n<>' ' do
  begin
    inc(o);
    a[o]:=n;
    read(n);
  end;
  readln(x);
  p:=1;
  while o>=p do
  begin
    for i:=p to o do
      if a[i]=x then inc(ans);
    a[o]:=chr(ord(a[o])-1);
    for i:=o downto p do
      if a[i]<'0' then
      begin
        a[o-1]:=chr(ord(a[o-1])-1);
        a[o]:='9';
      end;
    if a[p]='0' then inc(p);
  end;
  writeln(ans);
  close(input);
  close(output);
end.
