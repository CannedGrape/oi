var
  n,m,k,x,i,count1,count2:longint;
  begin
    assign(input,'circle.in');
    reset(input);
    assign(output,'circle.out');
    rewrite(output);
   readln(n,m,k,x);
    count1:=0;
     i:=1;
    while count1<k do
         begin
         i:=i*10; inc(count1);
         end ;
    count2:=0;
    while count2<i do
     begin
      if x+m<n then x:=x+m else
      if x+m>=n then x:=x+m-n;
      inc(count2);
     end;
    writeln(x);
    close(input);
    close(output);
  end.
