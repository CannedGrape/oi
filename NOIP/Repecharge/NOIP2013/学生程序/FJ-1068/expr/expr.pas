program expr;
  var s:string;
  var ans:longint;

procedure init;
  begin
    assign(input,'expr.in');reset(input);
    readln(s);
    s:=s+'.';
    close(input);
  end;

procedure work;
  var i,temp,temp2:longint;
  begin
    i:=1;
    temp:=0;
    temp2:=0;
    while i<=length(s) do
    begin
      if s[i]in['0'..'9'] then temp:=(temp*10+ord(s[i])-48)mod 10000 else
      if s[i]='+' then
      begin
        if temp2<>0 then begin ans:=ans+temp*temp2;temp2:=0;end
        else ans:=ans+temp;
        temp:=0;
        temp2:=0;
      end else
      if s[i]='*' then
      begin
        temp2:=temp;
        temp:=0;
      end else
      if s[i]='.' then if temp2 <>0 then ans:=ans+temp*temp2 else ans:=ans+temp;
      i:=i+1;
    end;
  end;
begin
  init;
  work;
  assign(output,'expr.out');rewrite(output);
  writeln(ans mod 10000);
  close(output);
end.
