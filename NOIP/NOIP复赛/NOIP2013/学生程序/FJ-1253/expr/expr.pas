var s,n:string;
    i,t,c,d,sum,p,q,j,num:longint;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(s);
  i:=1;t:=0;num:=1;
  while (s[i]>='0')and(s[i]<='9') do inc(i);
  repeat
    case s[i] of
    '+':begin
          if (t<>i)and(t+1<>i) then val(copy(s,t+1,i-t-1),c) else
            val(copy(s,t,i-t),c);
          sum:=sum+c;
          t:=i;
        end;
    '*':begin
          if (t<>i)and(t+1<>i) then val(copy(s,t+1,i-1-t),c) else
            val(copy(s,t,i-t),c);
          p:=i+1;
          i:=i+1;
          while (s[i]>='0')and(s[i]<='9') do begin inc(i);inc(q);end;
          val(copy(s,p,q),d);
          sum:=sum+c*d;
          t:=i;
        end;
    end;
    inc(i);
  until i>=length(s);
  case s[t] of
  '+':begin
        val(copy(s,t+1,length(s)-t),c);
        sum:=sum+c;
      end;
  '*':begin
        val(copy(s,t+1,length(s)-t),c);
        sum:=sum*c;
      end;
  end;
  str(sum,n);
  if length(n)<=4 then writeln(sum) else
  begin
    j:=length(n)-3;
    while n[j]='0' do inc(j);
    for i:=j to length(n) do write(n[i]);
  end;
  close(input);
  close(output);
end.
