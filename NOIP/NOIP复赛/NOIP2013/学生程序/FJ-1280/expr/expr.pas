var ans:int64;
    s:ansistring;
    s1:string;
    a:array[1..100001] of int64;
    b:array[1..100001] of char;
    z:array[1..50001] of int64;
    i,j,n,k,tot,t,t1,t2,code:longint;
function shuzi(c:char):boolean;
var temp:integer;
begin
 temp:=ord(c); if (57>=temp) and (temp>=48) then shuzi:=true else shuzi:=false;
 end;

begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 readln(s);
 i:=1;    t1:=1;t2:=1;
 while i<=length(s) do begin
  j:=i; tot:=0;
  while (j<=length(s)) and (shuzi(s[j]))  do begin inc(tot);inc(j); end;
  s1:=copy(s,i,tot);  val(s1,t,code);  a[t1]:=t; inc(t1);
  if j<length(s) then begin b[t2]:=s[j]; inc(t2);  end; i:=j+1;
  end;
  b[t2]:='+';

  i:=1;
while i<t1 do begin

 if b[i]='+' then begin  z[i]:=a[i]; a[i]:=0; inc(i);  end

 else if (b[i]='*') and (b[i+1]<>'*') then begin
   z[i]:=a[i]*a[i+1];a[i]:=0;a[i+1]:=0; inc(i); end

 else begin
  j:=i; tot:=1; while b[j+1]='*' do inc(j);
  for t:=i to j do begin tot:=tot*a[t];a[t]:=0; end;
  z[i]:=tot;
  i:=j+1;
  end;

  end;

 ans:=0;
 for i:=1 to t1 do ans:=ans+z[i];
 str(ans,s1);
 if length(s1)>4 then
 delete(s1,1,length(s1)-4);

 while (s1[1]='0') and (length(s1)>1) do delete(s1,1,1);

 writeln(s1);
 close(input);close(output);
  end.
