var s,t,v:string;
    a:array[1..100001] of longint;
    i,j,k,n,m,len,len2,len1,tt,g,x1,x2,total:longint;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(s);
  len:=length(s);
  k:=0;
  if (pos('*',s)<>0) and (pos('+',s)=0) then k:=pos('*',s);
  if (pos('+',s)<>0) and (pos('*',s)=0) then k:=pos('*',s);
  if (pos('*',s)<>0) and (pos('*',s)<pos('+',s)) then k:=pos('*',s);
  if (pos('+',s)<>0) and (pos('+',s)<pos('*',s)) then k:=pos('+',s);
  while k<>0 do
  begin
  if (s[k]='+') then
    begin
      t:=copy(s,1,k-1);
      delete(s,1,k);
      g:=length(t);
      if g>4 then t:=copy(t,g-3,4);
      inc(i);
      val(t,a[i],tt);
    end;
  if s[k]='*' then
    begin
      t:=copy(s,1,k-1);
      len1:=length(t);
      if len1>4 then t:=copy(t,len1-3,4);
      val(t,x1,tt);
      g:=k+1;
      m:=0;
      while (s[g]<>'+') and (s[g]<>'*') and (g<len) do begin inc(g); inc(m); end;
      t:=copy(s,k+1,m);
      delete(s,1,k+m);
      len2:=length(t);
      if len2>4 then t:=copy(t,len2-3,4);
      val(t,x2,tt);
      inc(i);
      a[i]:=x1*x2;
    end;
    k:=0;
    if (pos('*',s)<>0) and (pos('+',s)=0) then k:=pos('*',s);
    if (pos('+',s)<>0) and (pos('*',s)=0) then k:=pos('*',s);
    if (pos('+',s)<>0) and (pos('*',s)<pos('+',s)) then k:=pos('*',s);
    if (pos('*',s)<>0) and (pos('+',s)<>0) and (pos('+',s)<pos('*',s)) then k:=pos('+',s);
  end;
  if s<>'' then
  begin
    inc(i);
    len:=length(s);
    t:=copy(s,2,len-1);
    len1:=length(t);
    if len1>4 then t:=copy(t,len1-3,4);
    val(t,a[i],tt);
    end;
    t:=copy(s,2,k-1);
    for j:=1 to i do
     total:=(total+a[j]) mod 10000;
    write(total);
    close(input);
    close(output);
  end.
