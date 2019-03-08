program expr;
var s:ansistring;
    s1:string;
    a,b,c:array[1..100000] of longint;
    i,j,k,head,l,k1,m:longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  j:=1; k:=1;
  for i:=1 to length(s) do
  begin
    if (ord(s[i])>=ord('0')) and (ord(s[i])<=ord('9')) then
    begin
      inc(l);
      if l=1 then head:=i;
    end
    else if l>0 then
    begin
      val(copy(s,head,l),a[j]);
      j:=j+1;
      l:=0;
      if s[i]='*' then begin
        b[k]:=j;
        k:=k+1;
      end;
    end;
  end;
  val(copy(s,head,l),a[j]);
  k1:=1;
  i:=1;
  repeat
    if b[k1]=i then begin c[i-1]:=a[i-1]*a[i]; i:=i+1; k1:=k1+1; end
    else begin c[i]:=a[i]; i:=i+1; end;
  until i>=j+1;
  for i:=1 to j do
    m:=c[i]+m;
  str(m,s1);
  if length(s1)>4 then s1:=copy(s1,length(s1)-3,4);
  i:=1;
  while s1[i]='0' do delete(s1,i,1);
  write(s1);
  close(input);
  close(output);
end.
