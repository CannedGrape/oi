program expr;
var
 s,s1,s2,s3,s4,s5:string;
 i,a,b,c,d,j,code,m,n,u:longint;
 r:array[1..4] of char;
begin
 assign(input,'expr.in');
 reset(input);
 assign(output,'expr.out');
 rewrite(output);
 readln(s);
 i:=1;
 while i<=length(s) do
 begin
  if s[i]='*' then
  begin
   b:=i;
   a:=i;
    while (s[a-1]>='0') and (s[a-1]<='9') do
      a:=a-1;
    s1:=copy(s,a,i-a);
    val(s1,c,code);
    while (s[b+1]>='0') and (s[b+1]<='9') do
      b:=b+1;
    s2:=copy(s,i+1,b-i);
    val(s2,d,code);
    j:=c*d;
    str(j,s3);
    s4:=copy(s,1,a-1);
    s5:=copy(s,b+1,length(s));
    s:=concat(s4,s3,s5);
   end;
   i:=i+1;
  end;
  i:=1;
  while i<=length(s) do
  begin
  if s[i]='+' then
  begin
   b:=i;
   a:=i;
    while (s[a-1]>='0') and (s[a-1]<='9') do
      a:=a-1;
    s1:=copy(s,a,i-a);
    val(s1,c,code);
    while (s[b+1]>='0') and (s[b+1]<='9') do
      b:=b+1;
    s2:=copy(s,i+1,b-i);
    val(s2,d,code);
    j:=c+d;
    str(j,s3);
    s4:=copy(s,1,a-1);
    s5:=copy(s,b+1,length(s));
    s:=concat(s4,s3,s5);
    i:=pos(s5,s)-1;
   end;
   i:=i+1;
  end;
 n:=1;
 for i:=length(s) downto 1 do
  begin
   if m<4 then
    begin
     r[n]:=s[i];
     n:=n+1;
     m:=m+1;
    end;
  end;
  i:=4;
 while r[i]='0' do
  i:=i-1;
 for u:=i downto 1 do
  if (r[u]>='0') and (r[u]<='9') then
  write(r[u]);
 close(input);
 close(output);
end.
