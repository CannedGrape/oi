var a:array[1..100000]of int64;
    b:array[0..100000]of char;
    c:array[1..100000]of longint;
    i,j,n,lena,lenb,ans,asd,l,zo:longint;
    s:ansistring;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 readln(s);
 lena:=length(s);
 ans:=1;asd:=0;
 for i:=1 to lena do
  if (s[i]='+') or (s[i]='*') then
   begin
    asd:=asd+1;
    val(copy(s,ans,i-ans),a[asd]);
    a[asd]:=a[asd] mod 10000;
    b[asd]:=s[i];
    ans:=i+1;
   end;
 inc(asd);
 val(copy(s,ans,lena-ans+1),a[asd]);l:=0;
 a[asd]:=a[asd] mod 10000;
 for i:=1 to asd do
  if b[i]='*' then
   begin
    inc(l);
    c[l]:=(a[i]*a[i+1])mod 10000;
   end
  else
   begin
    inc(l);
    if (b[i-1]<>'*') then c[l]:=a[i]
   end;
 for i:=1 to l do
  zo:=zo+c[i];
 zo:=zo mod 10000;
 writeln(zo);
close(input);close(output);
end.
