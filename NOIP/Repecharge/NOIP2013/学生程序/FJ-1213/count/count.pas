var n,x,i,j,t:longint;s:string;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
    readln(n,x);
    for i:=1 to n do
    begin
      str(i,s);
      for j:=1 to length(s) do
        if ord(s[j])-48=x then inc(t);
    end;
    writeln(t);
  close(input);close(output);
end.
