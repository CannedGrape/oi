var
ans1:ansistring;
c:char;
a,a1:array[1..100000]of integer;
b:array[1..100000]of char;
s,i,a1d,bd,i1,t,ans,bb,pp:longint;
procedure btbtbtbt;
begin
  i1:=0;  a1d:=0;
  while i1<>s do
  begin
    inc(i1);
    t:=0;
    if a[i1]<>-1 then
    begin
      for i:=i1 to s do
      begin
        if a[i]=-1 then
        begin
          inc(a1d);
          a1[a1d]:=t;
          i1:=i;
          break;
          end;
        t:=t*10+a[i];
        end;
      end;
    end;
  a1[a1d+1]:=0;
  for i:=bb+1 to s do a1[a1d+1]:=(a1[a1d+1]*10)+a[i];
  inc(a1d);
end;
begin
  assign(input,'expr.in');reset(input);
  assign(input,'expr.out');rewrite(output);
  bd:=0;s:=0;
  while not eoln do
  begin
    inc(s);
    read(c);
    if (c<>'+')and(c<>'*') then
    val(c,a[s])
    else begin
      a[s]:=-1;
      inc(bd);
      b[bd]:=c;
      bb:=s;
      end;
    end;
  btbtbtbt;
  i:=0;
  while i<>a1d-1 do
  begin
    inc(i);
    if b[i]='*' then
    begin
      a1[i+1]:=a1[i]*a1[i+1];
      a1[i]:=0;
      end;
    end;
  ans:=0;
  for i:=1 to a1d do ans:=ans+a1[i];
  str(ans,ans1);
  if length(ans1)>4 then delete(ans1,1,length(ans1)-3);
  pp:=1;
  while ans1[pp]='0' do inc(pp);
  for i:=pp to length(ans1) do write(ans1[i]);
  close(input);
  close(output);
end.

