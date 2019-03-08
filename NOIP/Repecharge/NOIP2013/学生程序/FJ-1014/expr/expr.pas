var str,str1:ansistring;
    i,j,m,n,k,p,ans:longint;
    a:array[1..100000] of longint;
    b:array[1..100000] of char;

function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);rewrite(output);
  read(str); str1:='';k:=0; p:=0; ans:=0;
  fillchar(a,sizeof(a),0);
  for i:=1 to length(str) do
  begin
    if (str[i]<>'+') and (str[i]<>'*') then
    begin
      str1:=str1+str[i];//writeln(1);
    end else
    begin
      inc(k);
      //writeln(str1);
      for j:=max(length(str1)-3,1) to length(str1) do
      begin
       a[k]:=a[k]*10+ord(str1[j])-ord('0');
      end;
      str1:='';
    end;
    if str[i]='+' then
    begin
     inc(p);b[p]:='+';
    end;
    if str[i]='*' then
    begin
     inc(p);b[p]:='*';
    end;
  end;
  begin
      inc(k);
      //writeln(str1);
      for j:=max(length(str1)-3,1) to length(str1) do
      begin
       a[k]:=a[k]*10+ord(str1[j])-ord('0');
      end;
      str1:='';
  end;
  n:=k;m:=p;
  for i:=1 to m do
   if b[i]='*' then
   begin
    a[i+1]:=a[i]*a[i+1] mod 10000;
    a[i]:=0;
   end;
  for i:=1 to n do
  ans:=(ans+a[i]) mod 10000;
  writeln(ans);
  close(input);close(output);
end.
