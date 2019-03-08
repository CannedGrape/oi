var  a,b:array[0..10000]of longint;
     h:array[0..100000]of longint;
     n,i,high,tt,max,ac,k,t:longint;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
 readln(n);
 fillchar(a,sizeof(a),0);max:=0;
 for i:=1 to n do begin read(h[i]);inc(a[h[i]]);if max<h[i]then max:=h[i]; end;
 tt:=0;
 for i:=1 to max do
   if a[i]>0 then
     begin
       inc(tt); b[tt]:=i;
     end;
 ac:=0;b[0]:=0;
 for i:=1 to tt do
   begin
     high:=b[i];k:=b[i]-b[i-1];
     t:=1;
     while t<=n  do
       begin
        while (h[t]<high) and(t<=n ) do inc(t);
        if t<=n then
         begin
          while (h[t]>=high) and(t<=n) do inc(t);
          inc(ac,k);
         end;
      end;
    end;
   writeln(ac);
close(input);
close(output);
end.

