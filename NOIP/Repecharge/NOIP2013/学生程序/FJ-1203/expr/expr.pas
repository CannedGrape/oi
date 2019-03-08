var
  a,b,i,c,d,e,code:longint;
  j,g,f:int64;
  s:ansistring;
  t:string;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(s);
  if s[1]<>'+' then s:='+'+s+'+0';
  while pos('*',s)<>0 do begin
    a:=pos('*',s);
    for i:=a-1 downto 1 do if s[i]in['+','*'] then begin b:=i;break;end;
    for i:=a+1 to length(s)do if s[i]in['+','*'] then begin c:=i;break;end;
    val(copy(s,b+1,a-b-1),d,code);
    val(copy(s,a+1,c-a-1),e,code);
    if (e=0)or(d=0)then j:=0 else
    j:=(d*e) mod 10000;
    str(j,t);
    s:=copy(s,1,b)+t+copy(s,c,length(s)-c+1);
  end;
  t:='';
  if s[1]='+' then delete(s,1,1);
  for i:=1 to length(s)do if s[i]in['0'..'9'] then t:=t+s[i] else begin
    val(t,g,code);
    f:=f+g;
    t:='';
  end;
  writeln(f mod 10000);
  close(input);
  close(output);
end.
