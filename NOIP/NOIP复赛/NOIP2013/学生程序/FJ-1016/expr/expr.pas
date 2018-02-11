var
  s:ansistring;
  s1:string;
  a1,a2,i,j,x,code:longint;
  ans:integer;
  a:array[1..100001]of integer;
  ch:array[1..100000]of char;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  i:=1;
  while length(s)>0 do
  begin
    a1:=pos('+',s);a2:=pos('*',s);
    if(a1<>0)or(a2<>0)then
      if((a1<a2)and(a1<>0))or(a2=0)then
      begin
        s1:=copy(s,1,a1-1);
        val(s1,x,code);
        if(x>=10000)then a[i]:=x mod 10000
        else a[i]:=x;
        ch[i]:='+';
        inc(i);
        delete(s,1,a1);
      end
      else
        if((a2<a1)and(a2<>0))or(a1=0)then
        begin
          s1:=copy(s,1,a2-1);
          val(s1,x,code);
          if(x>=10000)then a[i]:=x mod 10000
          else a[i]:=x;
          ch[i]:='*';
          inc(i);
          delete(s,1,a2);
        end
        else continue
    else
    begin
      val(s,a[i],code);
      break;
    end;
  end;
  for j:=1 to i-1 do
    if(ch[j]='*')then
    begin
      x:=a[j+1]*a[j];
      if(x>=10000)then a[j+1]:=x mod 10000
      else a[j+1]:=x;
      a[j]:=0;
    end;
  ans:=0;
  for j:=1 to i do
  begin
    ans:=ans+a[j];
    if(ans>=10000)then ans:=ans mod 10000;
  end;
  writeln(ans);
  close(input);
  close(output);
end.