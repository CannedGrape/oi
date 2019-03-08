program expr;
 var i,j,n,len:longint;
     s:char;
     a:array[0..100000] of longint;
     ans:int64;
     se,we:ansistring;
     qq:string;
 begin
   assign(input,'expr.in');reset(input);
   assign(output,'expr.out');rewrite(output);
   fillchar(a,sizeof(a),0);
   ans:=0;
   n:=1;
   se:='';
   while not(eof) do
    begin
      read(s);
      if (s>='0') and (s<='9') then
       a[n]:=a[n]*10+(ord(s)-48);
      if (s='+') or (s='*') then
       begin
         inc(n);
         se:=se+s;
       end;
    end;
   len:=length(se);
   for i:=1 to len do
    if se[i]='*' then
     begin
       a[i+1]:=((a[i] mod 10000)*(a[i+1] mod 10000)) mod 10000;
       a[i]:=0;
     end;
   for i:=1 to n do
    ans:=(ans+a[i]) mod 10000;
   str(ans,we);
   len:=length(we);
   qq:=copy(we,len-3,4);
   len:=1;
   while (qq[len]='0') and (len<4) do inc(len);
   for i:=len to 4 do
    write(qq[i]);
   close(input);
   close(output);
 end.
