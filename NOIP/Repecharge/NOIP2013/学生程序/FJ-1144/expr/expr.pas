var
  i,j,n,m,x,k,ans,tmp,y,a,b:longint;
  code:integer;
  s,s1:ansistring;
  flag:boolean;
  f:Array[0..10001] of longint;
  t:Array[0..10001] of longint;
procedure dg(g,total:longint);
begin
  if g=k then begin ans:=total mod 10000;exit;end;
  if t[g]=1 then
  begin
    if flag then tmp:=(((f[g]*f[g+1]) mod 10000)) mod 10000
    else tmp:=(tmp*f[g+1]) mod 10000;
    flag:=false;
    if t[g+1]=1 then
    begin
      dg(g+1,total);
    end
    else begin flag:=true;dg(g+2,(total+tmp) mod 10000);end;
  end
  else
  begin
    flag:=true;dg(g+1,(total+f[g])mod 10000);
  end;
end;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  s:=s+'+';
  i:=1;j:=1;k:=1;flag:=false;tmp:=1;x:=1;
  y:=pos('*',s);
  while i<=length(s) do
  begin
    if (s[i]<>'+') and (s[i]<>'*') then begin inc(i);continue; end;
    if i=y then y:=k;
    s1:=copy(s,x,i-x);
    x:=i+1;
    val(s1,f[j],code);
    f[j]:=f[j] mod 10000;
    inc(j);
    if s[i]='+' then t[k]:=0 else t[k]:=1;
    inc(k);
    inc(i);
  end;
  flag:=true;
  dg(1,0);
  write(ans);
  close(input);
  close(output);
end.
