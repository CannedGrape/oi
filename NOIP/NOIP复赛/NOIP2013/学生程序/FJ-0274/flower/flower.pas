program flower;
 var n,i,t1,t2,x:longint;
     p:boolean;
     a:array[1..100000] of longint;
 begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
   readln(n);for i:=1 to n do read(a[i]);
    t1:=0;i:=1;p:=true;x:=maxlongint;
     while (i<=n) do
      begin
       if p then begin
        while (i<=n) and (a[i]>a[i+1]) do inc(i);
        if a[i]<x then begin
         inc(t1);x:=a[i];inc(i);p:=not(p);
                       end;
                 end
       else begin
        while (i<=n) and (a[i]<a[i+1]) do inc(i);
        if a[i]>x then begin
         inc(t1);x:=a[i];inc(i);p:=not(p);
                       end;
            end;
      end;

    t2:=0;i:=1;p:=true;x:=-1;
     while (i<=n) do
      begin
       if p then begin
        while (i<=n) and (a[i]<a[i+1]) do inc(i);
        if a[i]>x then begin
         inc(t2);x:=a[i];inc(i);p:=not(p);
                       end;
                 end
       else begin
         while (i<=n) and (a[i]>a[i+1]) do inc(i);
          if a[i]<x then begin
          inc(t2);x:=a[i];inc(i);p:=not(p);
                         end;
            end;
      end;

     if t1>t2 then write(t1)
      else write(t2);
  close(input);close(output);
 end.
