program count;
  var a:array[1..1000000] of longint;
      i,j,n,x,k,t:longint;s:ansistring;
  begin
    assign(input,'count.in');
    reset(input);
    assign(output,'count.out');
    rewrite(output);
    readln(n,x);
    for i:=1 to n do
      begin
         k:=i;
         str(k,s);
         for j:=1 to length(s) do
            if (ord(s[j])-48)=x then inc(t);
      end;
    write(t);
    close(input);
    close(output);
  end.
