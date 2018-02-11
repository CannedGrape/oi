program expr;
var
  i,j,n,k,tot,l,sum:longint;
  f:array[0..100005] of char;
  t:array[0..100005] of longint;
  s,s1,a:string;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  l:=length(s);
  sum:=0;
  fillchar(t,sizeof(t),0);
  for i:=1 to l do
    f[i]:='/';
  s1:='';
  j:=1;
  for i:=1 to l do
  begin
    if s[i]='+' then begin f[j]:='+'; inc(j); val(s1,t[j-1]); s1:=''; tot:=i; end;
    if s[i]='*' then begin f[j]:='*'; inc(j); val(s1,t[j-1]); s1:=''; tot:=i; end;
    if (s[i]>='0') and (s[i]<='9') then s1:=s1+s[i];
  end;
  a:=copy(s,tot+1,l-tot);
  val(a,t[j]);
  for i:=1 to j do
  begin
    if f[i]='*' then begin t[i+1]:=t[i+1]*t[i]; continue; end;
    sum:=sum+t[i];
  end;
  if sum=0 then begin writeln('0'); close(input); close(output); exit; end;
  str(sum,a);
  l:=length(a);
  if l<4 then write(a) else
  for i:=l-3 to l do
  if a[i]<>'0' then write(a[i]);
  close(input);
  close(output);
end.
