var s:array[1..999]of longint;
    ch:array[0..999]of char;
    h,i,j,k:longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  i:=1;
  ch[0]:='x';
  while ch[i-1]<>' ' do
   begin
    read(s[i]);
    read(ch[i]);
    inc(i);
   end;
  j:=i;
  for i:=1 to j do
   begin
     if(ch[i]='*')then
      begin
       s[i]:=s[i]*s[i+1];
       s[k+1]:=0;
      end;
   end;
  for i:=1 to j do
   begin
     if(ch[i]='+')then
      begin
       for k:=i downto 1 do if(s[k]<>0)then break;
       if(s[k]=0)then k:=i+2;
       h:=h+s[k]+s[i+1];
       s[k]:=0;
      end;
   end;
  write(h);
  close(input);
  close(output);
end.
