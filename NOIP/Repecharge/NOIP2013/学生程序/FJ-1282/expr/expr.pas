var t,r,s1,s2,s:ansistring;
    i,j,m,n:longint;math1,math2,ans:int64;
//==========================
 begin
 assign(input,'expr.in');reset(input);
 assign(output,'expr.out');rewrite(output);
  readln(s);
  t:='+';
  r:='*';
  repeat
  j:=pos(r,s);
  if j<>0 then begin
    m:=j-1;
    n:=j+1;
     while (ord(s[m])<=57) and (ord(s[m])>=48) do
       dec(m);
      s1:=copy(s,m+1,j-m-1);
     while (ord(s[n])<=57) and (ord(s[n])>=48) do
      inc(n);
      s2:=copy(s,j+1,n-j-1);
     val(s1,math1);
     val(s2,math2);
       delete(s,m+1,n-m-1);
    str(math1*math2 mod 10000,s1);
    insert(s1,s,m+1);
    end;
  until j=0;

  repeat
  j:=pos(t,s);
   if j<>0 then begin
    m:=j-1;
    n:=j+1;
     while (ord(s[m])<=57) and (ord(s[m])>=48) do
       dec(m);
      s1:=copy(s,m+1,j-m-1);
     while (ord(s[n])<=57) and (ord(s[n])>=48) do
      inc(n);
      s2:=copy(s,j+1,n-j-1);
     val(s1,math1);
     val(s2,math2);
       delete(s,m+1,n-m-1);
     str(math1+math2 mod 10000,s1);
      insert(s1,s,m+1);
    end;

  until j=0;

  val(s,ans);
  writeln(ans mod 10000);
  close(input);close(output);
 end.

