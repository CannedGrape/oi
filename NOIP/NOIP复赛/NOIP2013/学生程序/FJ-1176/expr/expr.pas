program expr;
var  s1,s2,x:ansistring;
  i,j,n,m,o,p,t,sum,ans:longint;
  bo:boolean;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s1);
  sum:=1; s2:='';
  for i:=length(s1) downto 1 do begin
    if s1[i]='+' then begin s1:=s1+'+';break;end;
    if s1[i]='*' then begin s1:=s1+'*';break;end;
    end;
  for i:=1 to length(s1) do
    begin
      if (s1[i]<>'+') and (s1[i]<>'*') then begin
      inc(m);insert(s1[i],x,i);
      if m>4 then
      begin
      delete(x,1,1);m:=m mod 4; end;
      end
      else begin
        if s1[i]='+' then begin
        if s2='*' then begin
        s2:='';
        val(x,p,t);
        sum:=sum*p;
        x:='';continue;
        end
        else begin
        m:=0;
        x:='';end;
        end
      else
      begin
        val(x,p,t);
        s2:='*';
        sum:=sum*p;
        x:='';if sum>=10000 then sum:=sum mod 10000;
      end;end;
    end;
    m:=0;
    for i:=1 to length(s1) do
      if (s1[i]<>'+') and (s1[i]<>'*') then begin
      inc(m);insert(s1[i],x,i);
      if m>4 then
      begin
      delete(x,1,1);m:=m-1; end;end
       else
       if s1[i]='+' then begin
        val(x,o,t);
        sum:=sum+o;
        if sum>=10000 then sum:=sum mod 10000;
        x:='';
        end
        else  if s1[i]='+' then begin m:=0;
        x:=''; end;
    writeln(sum);
    close(input);
    close(output);
end.
