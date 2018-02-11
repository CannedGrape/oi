var
  s:ansistring;
  p,j,k:longint;
  t,t1:string;
  tc:string;
  tt,tt1:int64;
  ttc:int64;
  c:longint;
  ans:int64;
  anss:string;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  p:=pos('*',s);
  while p>0 do
    begin
    j:=p-1;
    while (j>0) and (s[j]<>'*') and (s[j]<>'+') do dec(j);
    inc(j);
    k:=p+1;
    while (k<=length(s)) and (s[k]<>'*') and (s[k]<>'+') do inc(k);
    dec(k);
    t:=copy(s,j,p-j);
    t1:=copy(s,p+1,k-p);
    val(t,tt,c);
    val(t1,tt1,c);
    ttc:=tt*tt1;
    str(ttc,tc);
    if length(tc)>4 then delete(tc,1,length(tc)-4);
    delete(s,j,k-j+1);
    insert(tc,s,j);
    p:=pos('*',s);
    end;
  s:=s+'+';
  while length(s)>0 do
    begin
    p:=pos('+',s);
    t:=copy(s,1,p-1);
    val(t,tt,c);
    ans:=tt+ans;
    delete(s,1,p);
    end;
  str(ans,anss);
  if length(anss)>4 then delete(anss,1,length(anss)-4);
  while (anss[1]='0') and (length(anss)>1) do delete(anss,1,1);
  writeln(anss);
  close(input);
  close(output);
end.
