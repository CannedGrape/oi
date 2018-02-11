program ex1;
  var n,x,ans,i,j:longint;
      x1,t:string;
   begin
     assign(input,'count.in'); reset(input);
     assign(output,'count.out'); rewrite(output);
     read(n,x);
   ans:=0;
   str(x,x1);
   for i:=1 to n do
     begin
      str(i,t);
      if pos(x1,t)<>0 then
        begin
         for j:=1 to length(t) do
           if x1=t[j] then inc(ans);
        end;
     end;
    writeln(ans);
     close(input); close(output);
   end.
