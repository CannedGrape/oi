program block;
 var n,i,j,time,sum,max,zs,fs:longint;
     h:array[0..100000]of integer;

begin
 {assign(input,'block.in');
 assign(output,'block.out');
 reset(input);
 reset(output); }

  max:=0;

  readln(n);
  for i:=1 to n do
     begin
      read(h[i]);
      if h[i]>max then max:=h[i];
     end;

  time:=0;

  zs:=n;
  fs:=0;

  for i:=1 to max do
     begin
       for j:=1 to n do
          begin
           sum:=1;
           dec(h[i]);
          end;
             if (h[i]<0) and (zs>=fs) then
               begin
                inc(fs);dec(zs);
                inc(sum);
                if (i=1) or (i=n)  then dec(sum);
                inc(time,sum);
               end;
             if (zs<fs) and (h[i]>0) then
               begin
                inc(fs);dec(zs);
                inc(sum);
                if (i=1) or (i=n)  then dec(sum);
                inc(time,sum);
               end;

      end;

  write(time);

{ close(input);
 close(output); }
end.
