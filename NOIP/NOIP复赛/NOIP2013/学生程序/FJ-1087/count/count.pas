const max=1000000;
var n3:string;
    i2:char;
    i,j,s,x2,x3,n2,n,x,t:integer;
    a,b:array[1..max] of string;
begin
 assign(input,'count.in');
 assign(output,'count.out');
 reset(input);
 rewrite(output);
 read(n);
 read(x);
 s:=0;
 x3:=0;
 n2:=n;
 x2:=x;
 a[1]:='1';
 a[2]:='2';
 a[3]:='3';
 a[4]:='4';
 a[5]:='5';
 a[6]:='6';
 a[7]:='7';
 a[8]:='8';
 a[9]:='9';
 a[10]:='10';
 a[11]:='11';
 a[12]:='12';
 a[13]:='13';
 a[14]:='14';
 a[15]:='15';
 a[16]:='16';
 a[17]:='17';
 a[18]:='18';
 a[19]:='19';
 a[20]:='20';
 a[21]:='21';
for i:=1 to n2 do
 begin
 t:=ord(a[i]);
 if t=x+48 then s:=s+1;
  if t>57 then

   begin
    x3:=x3+length(a[i]);
    for j:=1 to length(a[i])  do
     begin
      n3:=a[i];
      b[j+x3]:=n3[j];
     end;
   end;
 end;
   for i:=0 to max do
   begin
   if ord(b[i])=x+48 then s:=s+1;
   end;
  writeln(s);
  close(input);
  close(output);
end.










