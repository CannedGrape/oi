var i,j,k,m,n,p,q,sum,total,max,min,tmp,x,y,a,b:longint;
    s,s1:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(n,m);
  if (m=0)then
  begin
    for i:=1 to n do
    begin
      str(i,s);
      while (s<>'') do
      begin
        a:=pos('0',s);
        if (a=0)then break
        else
        begin
          inc(sum);
          delete(s,1,a);
        end;
      end;
    end;
    write(sum);
    close(input);
    close(output);
    halt;
  end;
  for i:=1 to n do
  begin
    tmp:=i;
    begin
      if tmp<10 then
      begin
        if tmp=m then inc(sum);continue;
      end;
      y:=tmp mod 10;
      if (y=m) then inc(sum);
      tmp:=tmp div 10;
      if tmp<10 then
      begin
        if tmp=m then inc(sum);continue;
      end;
      while tmp>=10 do
      begin
        x:=tmp div 10;
        if (x=m) then inc(sum);
        str(tmp,s);
        tmp:=tmp mod ((length(s)-1)*10);
      end;
     end;
  end;
  write(sum);
  close(input);
  close(output);

end.
