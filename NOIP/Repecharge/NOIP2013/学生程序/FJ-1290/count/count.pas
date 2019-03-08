var m,n,k,sum,i:longint;
    a,x:string;
 begin
   assign(input,'count.in');
   reset(input);
   assign(output,'count.out');
   rewrite(output);
   read(n,m);
   str(m,x);
   for i:=1 to n do
    begin
      str(i,a);
      k:=1;
      while k<=length(a) do begin
                              if a[k]=x then sum:=sum+1;
                            k:=k+1;
                            end;
    end;
  writeln(sum);
  close(input);close(output);
end.
