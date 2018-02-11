var a,f:array[0..1000005]of int64;
    n,i:longint;
    max,js,p,t:int64;
begin
 assign(input,'number.in');reset(input);
 assign(output,'number.out');rewrite(output);
 read(n,p);
 read(a[1]);
 max:=a[1]+a[1];t:=a[1];f[1]:=a[1];js:=f[1];
 for i:=2 to n do
  begin
   read(a[i]);
   if (t+a[i])<a[i] then t:=a[i]
                    else begin t:=t+a[i];a[i]:=t; end;
   f[i]:=max;
   if f[i]+a[i]>max then max:=f[i]+a[i];
   if f[i]>js then js:=f[i];
  end;
  write(js mod p);

 close(input);close(output);
end.
