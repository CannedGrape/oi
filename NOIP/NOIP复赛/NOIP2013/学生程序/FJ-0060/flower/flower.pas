var  n,i,j,x1,xx:longint;
     ans:int64;
     a:array[0..1000000]of longint;
     t,tt:boolean;
begin
  assign(input,'flower.in');
  assign(output,'flower.out');
   reset(input);
   rewrite(output);
  readln(n);
  t:=true;ans:=2;xx:=1;x1:=1;
   for i:=1 to n do
    begin
     read(a[i]);
     if a[i]<>a[1] then t:=false;
    end;
  //a[n+1]:=a[n];
  for i:=1 to n-1 do
   begin
    if a[i+1]=a[i] then continue;
    if a[i+1]>a[i] then
     begin j:=i;repeat tt:=true;j:=j+1;until (a[j+1]<a[j])or(j>n);break;end;
    if a[i+1]<a[i] then
     begin j:=i;repeat tt:=false;j:=j+1;until (a[j+1]>a[j])or(j>n);break;end;
   end;
  if t then writeln(1) else
   begin
    if j<n then
      repeat
       if a[j]=a[j+1] then begin inc(j);continue;end;
       if a[j+1]>a[j] then
        begin
          if (not tt) then begin tt:=true;inc(ans);inc(j);
           if x1>=2 then inc(ans);
           x1:=1;continue;end;
          while (a[j+1]>=a[j])and(j+1<=n)and tt do
           begin
            inc(j);inc(xx);
           end;
         if(j=n)and(xx>=2)then inc(ans);
        end
       else
        begin
          if (tt) then begin tt:=false;inc(ans);inc(j);
          if xx>=2 then inc(ans);
          xx:=1;continue;end;
          while (a[j+1]<=a[j])and(j+1<=n)and (not tt) do
           begin
            inc(j);inc(x1);
           end;
          if (j=n)and(x1>=2) then inc(ans);
        end;
      until j>n-1;
   //if a[n]<>a[n-1] then inc(ans);
   if (ans=2)or(n=2) then writeln(1)else writeln(ans);
  end;
 close(input);
 close(output);
end.
