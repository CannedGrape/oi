program expr;
var
  m,i,j,k,t,n,l,p,q,tt,sum:longint;
  s,ss:ansistring;
  a,b,c,d:array[0..100006] of longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  fillchar(c,sizeof(c),0);
  t:=pos('*',s);
  while t<>0 do
   begin
     fillchar(a,sizeof(a),0);
     fillchar(b,sizeof(b),0);
     p:=t-1;
     k:=0;
     repeat
       inc(k);
       a[k]:=ord(s[p])-48;
       dec(p);
     until (p=0) or (s[p]<'0') or (s[p]>'9');
     q:=t;
      repeat
         inc(q);
       until (q>length(s)) or (s[q]<'0') or (s[q]>'9');
     l:=0;
     for i:=q-1 downto t+1 do
       begin
         inc(l);
         b[l]:=ord(s[i])-48;
       end;
    n:=l+k;
    for i:=1 to n do
     begin
       tt:=0;
       for j:=1 to n do
         begin
           sum:=a[i]*b[j]+tt;
           d[j]:=sum mod 10;
           tt:=sum div 10;
         end;
       d[n+1]:=tt;
       tt:=0;
       for j:=1 to n do
        begin
          sum:=c[i+j-1]+d[j]+tt;
          c[i+j-1]:=sum mod 10;
          tt:=sum div 10;
        end;
     end;
     m:=n;
     while (c[m]=0) and (m>0) do dec(m);
     ss:='';
     if m>0 then
       begin
         for i:=m downto 1 do ss:=ss+chr(c[i]+48);
         delete(s,p+1,n+1);
         insert(ss,s,p+1);
       end;
     t:=pos('*',s);
     fillchar(c,sizeof(c),0);
   end;
   t:=pos('+',s);
   while t<>0 do
     begin
       fillchar(a,sizeof(a),0);
       fillchar(b,sizeof(b),0);
       p:=t-1;
       k:=0;
       repeat
         inc(k);
         a[k]:=ord(s[p])-48;
         dec(p);
       until (p=0) or (s[p]<'0') or (s[p]>'9');
       q:=t;
       repeat
         inc(q);
       until (q>length(s)) or (s[q]<'0') or (s[q]>'9');
       l:=0;
       for i:=q-1 downto t+1 do
         begin
           inc(l);
           b[l]:=ord(s[i])-48;
         end;
       n:=l+k;
       tt:=0;
       for i:=1 to n do
         begin
           sum:=a[i]+b[i]+tt;
           c[i]:=sum mod 10;
           tt:=sum div 10;
         end;
     m:=n;
     while (c[m]=0) and (m>0) do dec(m);
     ss:='';
     if m>0 then
       begin
         for i:=m downto 1 do ss:=ss+chr(c[i]+48);
         delete(s,p+1,n+1);
         insert(ss,s,p+1);
       end;
     t:=pos('+',s);
     fillchar(c,sizeof(c),0);
     end;
  if length(s)>=4 then
    begin
     m:=l-3;
     while (s[m]='0') and (m>0) do inc(m);
     for i:=m to l do write(s[i]);
    end
    else
  writeln(s);
  close(input);
  close(output);
end.