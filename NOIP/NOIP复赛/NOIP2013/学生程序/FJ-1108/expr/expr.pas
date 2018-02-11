program expr;
var sum,x,h:longint;
  str1:ansistring;
  str2:string;
  can:boolean;
  a:array[1..100000]of char;
  b:array[1..100000]of longint;
  c:array[1..100000]of longint;
procedure main;
var ch:char;
  m,n:string;
  t1,w,t2,i,s:longint;
begin
  readln(str1);
  t1:=0;t2:=0;w:=0;i:=1;
  while i<=length(str1) do
  begin
    s:=-1;m:='';
    if (ord(str1[i])>=ord('0')) and (ord(str1[i])<=ord('9')) then s:=0;
    while (ord(str1[i])>=ord('0')) and (ord(str1[i])<=ord('9')) do
    begin
      m:=m+str1[i];
      inc(i);
    end;
    if length(m)<=4 then val(m,s) else val(copy(m,length(m)-3,4),s);
    if s<>-1 then if (str1[i]='*') or (a[t1]='*') then
     begin
       inc(w);
       c[w]:=s;
     end else
     begin
       inc(t2);
       b[t2]:=s;
     end;
    if i<>length(str1) then
    begin
      inc(t1);
      a[t1]:=str1[i];
    end;
    case a[t1-1] of
    '+':
    begin
      inc(sum,b[t2]);
      a[t1-1]:=a[t1];dec(t1);
      b[t2]:=0;dec(t2);
    end;
    '*':if a[t1]<>'*' then
    begin
      inc(sum,c[w]*c[w-1]);
      c[w]:=0;c[w-1]:=0;dec(w,2);
      a[t1-1]:=a[t1];dec(t1);
    end;
    end;
    inc(i);
  end;
end;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  main;
  str(sum,str2);x:=1;
  if 4<=length(str2) then delete(str2,1,length(str2)-4);
  while str2[x]='0' do inc(x);
  for h:=x to length(str2) do write(str2[h]);
  close(input);
  close(output);
end.

