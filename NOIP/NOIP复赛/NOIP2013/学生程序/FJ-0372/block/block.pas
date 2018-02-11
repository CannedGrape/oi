program block;
var n,i,x,y,k:integer;
    h:array[0..10000] of integer;
    b:array[0..10000] of integer;

procedure f;
  begin
      for i:=x to y do
        begin
          inc(b[i]);
          k:=k+1;
        end;
  end;



begin
   assign(input,'block.in');reset(input);
   assign(output,'block.out');rewrite(output);
      readln (n);
      for i:=1 to n do
         begin
            read(h[i]);
         end;
    b[i]:=0;
   while b[i]<>h[i] do
      begin
          f
      end;
   close(input);
   write(k);
   close(output);

end.
