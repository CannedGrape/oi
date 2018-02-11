program NOIP2013expr;
  var s:ansistring; s1:string;
      tot:int64; t:longint;
  procedure times(x:longint);
    var i,j:longint;
        temp1,temp2:longint;
    begin
      i:=x;
      j:=x;
      while (s[i]<>'+') and (i<>1) do i:=i-1;
      while (s[j]<>'+') and (j<>length(s)) do j:=j+1;
      val(copy(s,i+1,x-i-1),temp1);
      val(copy(s,x+1,j-x-1),temp2);
      delete(s,i+1,j-1);
      str(temp1*temp2,s1);
      insert(s1,s,i+1);
    end;
  procedure plus;
    begin
      tot:=ord(s[1])-48;
      delete(s,1,1);
      while s<>'' do
        begin
          delete(s,1,1);
          tot:=tot+ord(s[1])-48;
        end;
    end;
  begin
    assign(input,'expr.in');
    assign(output,'expr.out');
    reset(input); rewrite(output);
      read(s);
      t:=pos('*',s);
      while t<>0 do times(t);
      if pos('+',s)<>0 then plus
      else val(s,tot);
    writeln(tot mod 10000);
    close(input);
    close(output);
  end.
