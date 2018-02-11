program expr;
var
  a:array[1..1000]of longint;
  b:array[1..1000]of string;
  s,he,q:string;
  a1,b1,l,i,j,n,h,f:longint;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(s);
  fillchar(a,sizeof(a),0);
  a1:=0;b1:=0;h:=0;f:=1;
  n:=length(s);
  for i:=1 to n do
  if (s[i]='*') or (s[i]='+') then begin inc(b1); b[b1]:=s[i];s[i]:='x'; end;
  s:=s+'x';
  for i:=1 to n do
  if s[i]='x' then
  begin
    inc(a1);
    q:=copy(s,f,i-1);
    writeln(q);
    val(q,a[a1]);
    f:=i+1;
  end;
  for i:=1 to b1 do
  if b[i]='*' then
  begin
    a[i+1]:=a[i+1]*a[i];a[i]:=0;b[i]:='0';
  end;
  for i:=1 to a1 do if a[i]=0 then begin a[i]:=a[i+1];a[i+1]:=0;end;
  {for i:=1 to b1 do if b[i]='0' then begin b[i]:=b[i+1];b[i+1]:='0';end;}
  for i:=1 to a1 do h:=h+a[i];
  str(h,he);
  if length(he)<=4 then writeln(he)
  else for i:=length(he)-3 to length(he) do if he[i]<>'0' then write(he[i]);
  writeln(h);
  close(input);close(output);
end.

