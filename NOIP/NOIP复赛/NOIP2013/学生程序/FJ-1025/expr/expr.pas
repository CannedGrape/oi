program expr;
var s:ansistring;
    jia:array[1..100000] of longint;
    cheng:array[1..100000] of longint;
    shu:array[1..1000001] of longint;
    i,a,b,c,f,l,j:longint;
    ans:int64;
    t:array[1..1000001]of boolean;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  a:=0;b:=0;c:=0;ans:=0;l:=length(s);
  for i:=1 to l do
    begin
      f:=f+1;
      if (s[i]='+')or (s[i]='*') then
      begin
        inc(a);
        if f>5 then
        shu[a]:=(ord(s[i-4])-48)*1000+(ord(s[i-3])-48)*100+(ord(s[i-2])-48)*10+ord(s[i-1])-48
        else if f=4 then shu[a]:=(ord(s[i-3])-48)*100+(ord(s[i-2])-48)*10+ord(s[i-1])-48
        else if f=3 then shu[a]:=(ord(s[i-2])-48)*10+ord(s[i-1])-48
        else if f=2 then shu[a]:=(ord(s[i-1]))-48;
        f:=0;
        if s[i]='+' then begin inc(a);shu[a]:=-1;end;
        if s[i]='*' then begin inc(a);shu[a]:=-2;end;

    end;
    end;
  inc(a);
  if f=4 then
        shu[a]:=(ord(s[l-3])-48)*1000+(ord(s[l-2])-48)*100+(ord(s[l-1])-48)*10+ord(s[l])-48
        else if f=3 then shu[a]:=(ord(s[l-2])-48)*100+(ord(s[l-1])-48)*10+ord(s[l])-48
        else if f=2 then shu[a]:=(ord(s[l-1])-48)*10+ord(s[l])-48
        else if f=1 then shu[a]:=(ord(s[l]))-48;
  fillchar(t,sizeof(t),true);
  for i:=1 to a do
  begin
  if (shu[i]=-2) and (t[i-1])then
  begin
    shu[i-1]:=shu[i-1]*shu[i+1];if shu[i-1]>1000 then shu[i-1]:=shu[i-1]mod 10000;
    t[i]:=false;t[i+1]:=false;
  end;
  if (shu[i]=-2) and (t[i-1]=false) then
  begin
    j:=i;
    while (j>0)and(t[j]=false) do
    dec(j);
    dec(j);
    shu[j]:=shu[j]*shu[i+1];shu[j]:=shu[j] mod 10000;
    t[i]:=false;t[i+1]:=false;
  end;
  end;
  ans:=shu[1];
  for i:=1 to a do
  begin
  if (shu[i]=-1) then
    begin
     ans:=ans+shu[i+1];ans:=ans mod 10000;
     t[i]:=false;t[i+1]:=false;
    end;
  end;
  write(ans mod 10000);
  close(input);
  close(output);
end.



