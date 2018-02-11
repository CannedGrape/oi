Program count;
  var
    s,s1:string;
    n,x,i,j,ans:longint;
    a:array[1..1000000] of longint;
  begin
    assign(input,'count.in');
    reset(input);
    assign(output,'count.out');
    rewrite(output);
    read(n,x);
    str(x,s);
    ans:=0;
    for i:=1 to n do
      begin
        a[i]:=i;
        str(a[i],s1);
        for j:=1 to length(s1) do
          if s1[j]=s then inc(ans);
      end;
    write(ans);
    close(input);
    close(output);
  end.
