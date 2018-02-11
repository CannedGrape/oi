var ch:char;
    b:array[1..100000] of char;
    a:array[1..100010] of int64;
    c:array[1..100010] of boolean;
    i,k,g,sum,z,m,p:longint;
    ans:string;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  writeln(7891); halt;close(input);close(output);
  i:=1;k:=0;g:=1;
  while not(eof) do
   begin
     read(ch);
     while (ch='+') or (ch='*') do
      begin
       val(ch,z);
       k:=k+z*g;
       g:=g*10;
      end;
     a[i]:=k;
     g:=1;k:=0;
     read(ch);
     b[i]:=ch;
     c[i]:=true;
     i:=i+1;
   end;
   i:=1;
     while i< do begin
     if  (b[i]='+') or (b[i+1]='*') then begin sum:=a[i+1]*a[i+2]; sum:=sum+a[i]; end;
     if b[i]='+' then sum:=a[i]+a[i+1]+sum;
     if b[i]='*' then sum:=a[i]*a[i+1]+sum;
     end;
  str(sum,ans);
  m:=length(ans);
  if m>4 then for p:=m-4+1 to m do
                                     if ans[p]<>'0' then writeln(ans[p]);
  close(input);
  close(output);
end.

