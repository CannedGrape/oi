var
  n,i,j,k,max,kk:longint;
  ans:int64;
  h:array[0..100000] of longint;
  bo:boolean;

begin
assign(input,'block.in'); reset(input);
assign(output,'block.out'); rewrite(output);
  readln(n);
  max:=-maxlongint div 3;
  for i:=1 to n do
   begin
     read(h[i]);
     if max<h[i] then max:=h[i];
   end;

  for k:=1 to max do
   begin
     bo:=false;
     kk:=0; i:=1;
     while i<=n do//for i:=1 to n do
      begin

        if h[i]<>0 then
         begin
           kk:=0;
           bo:=true;
           dec(h[i]);
           if i=n then inc(ans);
         end
        else

        if (h[i]=0) then
        begin
          inc(kk);
          if (bo=true) then
           begin
             inc(ans);

             bo:=false;
           end;
        end;


        if i=n then n:=n-kk;


        inc(i);



      end;

   end;

  writeln(ans);



close(input); close(output);
end.
