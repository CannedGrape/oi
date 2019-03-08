program number;
 var i,j,n,p,s,max1,s1:longint;a,b:array[0..1000000]of longint;
 begin
 assign(input,'number.in');reset(input);
 assign(output,'number.out');rewrite(output);
 readln(n,p);    max1:=-maxlongint;
 for i:=1 to n do read(a[i]);
 for i:=1 to n do
  begin
  s:=0;
 for j:=i downto 1 do
    begin
    s:=s+a[j];
    if s>=a[i] then b[i]:=s;
    end;   end;

  if b[1] mod p>max1 then max1:=b[1];
    for i:=2 to n do
   begin
    s:=0; s1:=0;
    for j:=(i-1)downto 1  do
     begin
  s:=b[j]+s;
   begin
    s1:=s+b[1];
    end;   end;
 if s1  mod p>max1 then max1:=s1;end;

  write(max1);
  close(input);
  close(output);
  end.

