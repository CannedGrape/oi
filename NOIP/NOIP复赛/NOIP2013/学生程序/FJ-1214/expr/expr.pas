var l,i,j,r:longint;
    s,tot:int64;
    a1:char;
    a:array[0..100001]of longint;
    b:array[0..100001]of boolean;
    s1:array[0..4000000]of char;
begin
  assign(input,'expr.in'); reset(input);
  assign(output,'expr.out'); rewrite(output);
  l:=0;
  repeat
   inc(l);
   read(s1[l]);
  until eof;
  for i:=1 to l do
  begin
   a1:=s1[i];
   if (a1>='0')and(a1<='9') then
        s:=(s*10+ord(a1)-48) mod 10000;
   if a1='*' then b[r+1]:=true;
   if (s1[i+1]>='0') and(s1[i+1]<='9') then  continue;
   inc(r); a[r]:=s;
   if b[r] then
    begin
      dec(r);
      a[r]:=(a[r]*a[r+1])mod 10000;
      a[r+1]:=0;
      b[r+1]:=false;
    end;
   s:=0;
  end;
  for i:=1 to r do tot:=(tot+a[i])mod 10000;
  writeln(tot);
  close(input); close(output);
end.
