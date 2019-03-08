var
  expr:ansistring;
  sum,i,j,k,temp,temp1,numtag1,numtag2,numtag,final,tag,flag,tim:longint;
  keng:array[1..1000000] of longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(expr);
  temp:=length(expr);
  final:=0;
  for i:=1 to temp do
  begin
    numtag1:=0;
    numtag2:=0;
    if i>length(expr) then break;
    if expr[i]='*' then
    begin
      temp1:=1;
      for j:=i-1 downto 1 do if expr[j]='+' then temp1:=j+1;
      for j:=i-1 downto temp1 do
      begin
        if (i-j-1)>0 then numtag1:=numtag1+((ord(expr[j])-48)*10) else numtag1:=numtag1+ord(expr[j])-48;
        for tag:=1 to j-temp1-1 do numtag1:=numtag1*10;
      end;
      numtag1:=numtag1 mod 10000;
      tim:=temp1;
      temp1:=temp;
      for j:=i+1 to temp do if (expr[j]='+') or (expr[j]='*') then temp1:=j-1;
      for j:=i+1 to temp1 do
      begin
        if (j-i-1)>0 then numtag2:=numtag2+((ord(expr[j])-48)*10) else numtag2:=numtag2+ord(expr[j])-48;
        for tag:=1 to temp1-j-1 do numtag2:=numtag2*10;
      end;
      numtag2:=numtag2 mod 10000;
      numtag:=(numtag1*numtag2) mod 10000;
      flag:=tim;
      if (numtag div 1000)>0 then
      begin
        expr[flag]:=chr(48+(numtag div 1000));
        flag:=flag+1;
      end;
      numtag:=numtag mod 1000;
      if (numtag div 100)>0  then
      begin
        expr[flag]:=chr(48+(numtag div 100));
        flag:=flag+1;
      end;
      numtag:=numtag mod 100;
      if (numtag div 10)>0 then
      begin
        expr[flag]:=chr(48+(numtag div 10));
        flag:=flag+1;
      end;
      numtag:=numtag mod 10;
      expr[flag]:=chr(48+numtag);
      flag:=flag+1;
      delete(expr,flag,temp1-flag+1);
    end;
  end;
  temp:=length(expr);
  sum:=0;
  flag:=1;
  for i:=1 to 1000000 do keng[i]:=0;
  for i:=1 to temp do
    if expr[i]='+' then
    begin
      for j:=i-1 downto 1 do
      begin
        if (i-j-1)>0 then keng[flag]:=keng[flag]+((ord(expr[j])-48)*10) else keng[flag]:=keng[flag]+ord(expr[j])-48;
        for tag:=1 to j-2 do keng[flag]:=keng[flag]*10;
      end;
      sum:=sum+keng[flag];
      sum:=sum mod 10000;
      delete(expr,i,1);
      if pos('+',expr)=0 then
        temp1:=length(expr)
      else temp1:=pos('+',expr);
      flag:=flag+1;
      for j:=i to temp1 do
      begin
        if (j-i)>0 then keng[flag]:=keng[flag]+((ord(expr[j])-48)*10) else keng[flag]:=keng[flag]+ord(expr[j])-48;
        for tag:=1 to temp1-j-1 do keng[flag]:=keng[flag]*10;
      end;
      sum:=sum+keng[flag];
      sum:=sum mod 10000;
      flag:=flag+1;
      if pos('+',expr)=0 then
      begin
        writeln(sum);
        close(input);
        close(output);
        halt;
     end;
    end;
  writeln(expr);
  close(input);
  close(output);
end.
