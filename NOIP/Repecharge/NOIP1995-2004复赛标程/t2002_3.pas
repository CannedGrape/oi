program t2002_3;
var h,s,v,L,k,t1,t2,h1,h2:real;
    i,n,n1,count:integer;
begin
    assign(input,'c.in');
    reset(input);
    readln(h,s,v,L,k,n);
    close(input);
    count:=0;
    n1:=n-1;
    while n1>s+L+0.00001 do n1:=n1-1;
    for i:=n1 downto 0 do begin
        t1:=(s-i-0.00001)/v;
        t2:=(s-i+L+0.00001)/v;
        h1:=5*t1*t1;
        h2:=5*t2*t2;
        if (L+0.00001<i) then begin
           if (h1<h) and (h2>=h-k-0.00001) then
               count:=count+1
           end
        else begin
           if (h1<h) then
                count:=count+1
          end;
    end;
    assign(output,'c.out');
    rewrite(output);
    writeln(count);
    close(output);
end.