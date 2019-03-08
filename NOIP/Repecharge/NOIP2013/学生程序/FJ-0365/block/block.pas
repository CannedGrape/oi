var g,h:array[1..100002] of longint;
  max,ans,min,i,j,n,k,l,m:longint;
    begin  assign(input,'block.in'); reset(input);
           assign(output,'block.out'); rewrite(output);
     min:=10001; max:=0;
      readln(n);
       for i:=1 to n do read(h[i]);

       for i:=1 to n do
        begin  if h[i]<min then min:=h[i]; if h[i]>max then max:=h[i]; end;
         ans:=min;
          for i:=1 to n do h[i]:=h[i]-min;

          for j:=1 to max do
           begin
            for i:=1 to n do
             begin
              if (h[i]>0) and (h[i+1]<=0) then inc(ans);
             end;
               for k:=1 to n do h[k]:=h[k]-1;
           end;

                writeln(ans);           close(input); close(output);
                end.