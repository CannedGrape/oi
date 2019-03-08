  var
    i,p,j,m,n,code,ans,len:longint;
    a,b:string;
    s:string;
    c:array[1..10000] of longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  while pos('*',s)>0 do
    begin
      p:=pos('*',s);
      i:=p-2;j:=p+2;
      while (i>=1) and (s[i]<>'+') and (s[i]<>'*') do
        dec(i);
      inc(i);
      while (j<=length(s)) and (s[j]<>'+') and (s[j]<>'*') do
        inc(j);
      dec(j);
      a:=copy(s,i,p-i);
      b:=copy(s,p+1,j-p);
      val(a,m,code);
      val(b,n,code);
      ans:=(m mod 10000)*(n mod 10000);
      ans:=ans mod 10000;
      delete(s,i,j-i+1);
      str(ans,a);
      insert(a,s,i);
    end;
  if pos('+',s)=0 then
    begin
      writeln(s);
      close(input);
      close(output);
      halt;
    end;
  i:=1;ans:=0;
  len:=length(s);
  for j:=2 to len do
    if (s[j]='+') or (j=len) then
      begin
        if j=len then
          a:=copy(s,i,j-i+1)
        else a:=copy(s,i,j-i);
        val(a,m,code);
        ans:=(ans+m mod 10000) mod 10000;
        i:=j+1;
      end;
  writeln(ans);
  close(input);
  close(output);
end.