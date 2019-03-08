var s:string[255];
    i,j,k,count,a,b:integer;
    s1,s2:longint;

procedure jieguo(q,w,e:longint);
var ii,jj,kk:integer;
    temp:char;
begin
   ii:=q;
   while(e>0) do
   begin
      jj:=e mod 10;
      s[ii]:=chr(ord('0')+jj);
      inc(ii);
      e:=e div 10;
   end;
   kk:=ii;
   ii:=ii-1;
   for jj:=q to q+(kk-q)div 2 do
   begin
      temp:=s[ii];
      s[ii]:=s[jj];
      s[jj]:=temp;
      ii:=ii-1;
   end;
   for jj:=kk to w do
   s[jj]:='!';
end;


function findnum1(m:integer):integer;
var ii:integer;
begin
   for ii:=m-1 downto 1 do
   begin
      if((ord(s[ii])<ord('0'))or (ord(s[ii])>ord('9')))and(not(s[ii]='!'))  then
      exit(ii+1);
   end;
   exit(1);
end;

function findnum2(m:integer):integer;
var ii:integer;
begin
   for ii:=m+1 to length(s) do
   begin
      if(ord(s[ii])<ord('0'))or (ord(s[ii])>ord('9'))  then
      exit(ii-1);
   end;
   exit(length(s));
end;

function shuzi(q,w:integer):longint;
var ii,jj,h:longint;
begin
h:=0;
for ii:=q to w do
begin
if(not(s[ii]='!'))   then begin
h:=h*10+(ord(s[ii])-ord('0'));
end;
end;
shuzi:=h;
end;

begin
assign(input,'expr.in');
assign(output,'expr.out');
reset(input);
rewrite(output);
read(s);
for i:=1 to length(s) do
begin
if(s[i]='*') then
begin
a:=findnum1(i);
b:=findnum2(i);
s1:=shuzi(a,i-1);
s2:=shuzi(i+1,b);
s1:=s1*s2;
jieguo(a,b,s1);
end;
end;
for i:=1 to length(s) do
begin
if(s[i]='+') then
begin
a:=findnum1(i);
b:=findnum2(i);
s1:=shuzi(a,i-1);
s2:=shuzi(i+1,b);
s1:=s1+s2;
jieguo(a,b,s1);
end;
end;
for i:=length(s) downto 1 do
begin
   if(not(s[i]='!'))   then   begin
   write(shuzi(1,i) mod 10000);
   close(input);
   close(output);
   halt;
   end;
end;
end.


