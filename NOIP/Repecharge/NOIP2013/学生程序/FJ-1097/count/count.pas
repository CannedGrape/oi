var
       n:longint;
       x:integer;
       i,j:longint;
       p:longint;
       s:string;
begin
      assign(input,'count.in');
      reset(input);
      assign( output,'count.out');
      rewrite(output);
          readln(n,x);  p:=0;
          for i:=1 to n do
             begin
               str(i,s);
               for  j:=1 to length(s) do
                    if ord(s[j])-ord('0')=x then
                       begin
                         inc(p);
                        
                       end;
             end;

          writeln(p);

      close(input);
      close(output); 

end.
