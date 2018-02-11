var
 s:char;
 a:array [1..100]of longint;
 b:array[1..100 ] of char;
 i,x:longint;
  begin
    assign(input,'expr.in');
    reset(input);
    assign(output,'expr.out');
    rewrite(output);
while not eoln do
begin
if s in ['0'..'9'] then
  begin
    repeat
      val(s,i);
      a[x]:=a[x]*10+i;
      a[x]:=a[x] mod 10000;
      read(s);
    until not(s in ['0'..'9']);
  end;
if s in ['*','+'] then b[x]:=s;
inc(x);
end;
for i:= 1 to x do
if b[i]='*' then
 begin
   a[i-1]:=a[i-1]*a[i+1];
   a[i+1]:=0;
   a[i-1]:=a[i-1] mod 10000;
 end;
for i:=1 to x do
if b[i]='+' then
 begin
   a[1]:=a[1]+a[i+1];
   a[1]:=a[1] mod 10000;
 end;
write(a[1]);
 close(input);
 close(output);
end.
