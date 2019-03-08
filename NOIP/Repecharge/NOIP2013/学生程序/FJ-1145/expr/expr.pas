var
s,k1:ansistring;
d,a,i,j,k,l:longint; q,b,c:int64;
function jg(s:ansistring):ansistring;
var i,j,k,l:longint;k1:string;
begin
  l:=length(s);
  k1:=copy(s,l-3,4);
  i:=1;
  while k1[i]='0' do inc(i); dec(i);
  delete(k1,1,i);
  exit(k1);
end;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  repeat
  a:=pos('*',s);
  if a<>0 then
  begin
    l:=length(s);
    for i:=a-1 downto 1 do if (s[i]='+')or(s[i]='*') then break;
    if i<>1 then inc(i);
    for j:=a+1 to l do
    if (s[j]='*')or(s[j]='+') then break;
    if j<>l then dec(j);
    val(copy(s,i,a-i),b);
    val(copy(s,a+1,j-a),c);
    str(b*c,k1);
    delete(s,i,j-i+1);
    insert(k1,s,i);
  end;
  a:=pos('*',s);
  until a=0;
    a:=pos('+',s);
   if a<>0 then
    begin
    s:=s+'+';
    for i:=1 to length(s) do
    if s[i]='+' then
    begin
     val(copy(s,d+1,i-d-1),b);
     inc(q,b);
    d:=i;
    end;
     str(q,k1);
     l:=length(k1);
     if l>4 then
     write(jg(k1)) else write(q);
    end else
    if length(s)>4 then
    write(jg(s)) else write(s);
    close(input);
    close(output);
end.
