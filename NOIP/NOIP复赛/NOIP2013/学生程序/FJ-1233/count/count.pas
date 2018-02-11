program NOIP2013count;
  var i,n,ans:longint;
      x,j:integer;
      s:string;
  begin
    assign(input,'count.in');
    assign(output,'count.out');
    reset(input); rewrite(output);
      read(n,x);
      ans:=0;
      s:='';
      for i:=1 to n do
        begin
          str(i,s);
          for j:=1 to length(s) do if ord(s[j])-48=x then ans:=ans+1;
        end;
      writeln(ans);
    close(input);
    close(output);
  end.
