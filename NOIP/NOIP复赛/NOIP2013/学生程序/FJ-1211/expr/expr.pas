var x:array [0..5000000] of char;
    n,i,j,t1,t2,s1,s2,ans:longint;
    str1,str2:string;
procedure print;
  var ii:longint;
  begin
    writeln(' n=',n,' i=',i,' ans=',ans);
    write(' ');
    for ii:=1 to n do write(x[ii]);
    writeln;
  end;
procedure delete(a,m:longint);
  var i,j:longint;
  begin
    for i:=1 to m do
      for j:=a+1 to n-i+1 do x[j-1]:=x[j];
    dec(n,m);
  end;
procedure insert(tstr:string;m:longint);
  var i,j,nn:longint;
  begin
    nn:=length(tstr);
    for i:=1 to nn do
    begin
      for j:=n+i-1 downto m do x[j+1]:=x[j];
      x[m]:=tstr[nn-i+1];
    end;
    inc(n,nn);
  end;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  i:=0;
  while not eoln do begin inc(i);read(x[i]); end;
  n:=i;
  i:=0;
  while i<n do
  begin
    inc(i);
    if x[i]='*' then
    begin
      j:=i-1;
      while (not ((x[j]='+') or (x[j]='*'))) and (j>1) do dec(j);
      if x[j] in ['+','*'] then inc(j);
      t1:=j;
      j:=i+1;
      while (not ((x[j]='+') or (x[j]='*'))) and (j<n) do inc(j);
      if x[j] in ['+','*'] then dec(j);
      t2:=j;
      str1:='';str2:='';
      if i-t1>=4 then
        for j:=i-4 to i-1 do str1:=str1+x[j]
      else for j:=t1 to i-1 do str1:=str1+x[j];
      if t2-i>=4 then
        for j:=t2-3 to t2 do str2:=str2+x[j]
      else for j:=i+1 to t2 do str2:=str2+x[j];
      val(str1,s1);
      val(str2,s2);
      ans:=s1*s2 mod 10000;
      delete(t1,t2-t1+1);
      str1:='';
      str(ans,str1);
      insert(str1,t1);
      i:=t1;
    end;
  end;
  ans:=0;
  i:=0;
  insert('+',1);
  while i<n do
  begin
    inc(i);
    if x[i]='+' then
    begin
      j:=i+1;
      while (not (x[j]='+')) and (j<n) do inc(j);
      if x[j]='+' then dec(j);
      t2:=j;
      str2:='';
      if t2-i>=4 then
        for j:=t2-3 to t2 do str2:=str2+x[j]
      else for j:=i+1 to t2 do str2:=str2+x[j];
      val(str2,s2);
      ans:=(ans+s2) mod 10000;
    end;
  end;
  writeln(ans);
  close(output);
  close(input);
end.
