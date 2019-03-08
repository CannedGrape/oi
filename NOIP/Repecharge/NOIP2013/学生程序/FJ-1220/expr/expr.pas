program ex;
  var a:array[0..100000]of int64;
      d:array[1..4]of byte;
      b:array[0..100000]of char;
      i,j,k,n,l,t:longint;
      c:char;
      s:string;
      f:boolean;
  begin
   assign(input,'expr.in');
   reset(input);
   assign(output,'expr.out');
   rewrite(output);
   i:=0;
   j:=0;
   f:=true;
   while not(eoln) do
    begin
     read(c);
     if (c<>'+')and(c<>'*') then
      s:=s+c
     else
      begin
       inc(i);
       val(s,a[i],l);
       if f=false then
        begin
         a[i-1]:=a[i]*a[i-1];
         dec(i);
         dec(j);
        end;
       inc(j);
       b[j]:=c;
       s:='';
       if j>1 then
        if b[j]=b[j-1] then
         begin
          if c='+' then
           a[i-1]:=a[i-1]+a[i]
          else a[i-1]:=a[i-1]*a[i];
          f:=true;
          dec(i);
          dec(j);
         end
        else
         if b[j]='*' then
          f:=false
         else
          begin
           a[i-1]:=a[i]*a[i-1];
           dec(i);
           b[j-1]:=b[j];
           dec(j);
          end;
       end;
    end;
   inc(i);
   val(s,a[i],l);
   if f=false then
    begin
     a[i-1]:=a[i]*a[i-1];
     dec(i);
     dec(j);
    end;
   if b[j]='+' then
    a[i-1]:=a[i]+a[i-1]
   else
    a[i-1]:=a[i-1]*a[i];
   t:=0;
   while (t<4)and(a[i-1]>0) do
    begin
     inc(t);
     d[t]:=a[i-1]mod 10;
     a[i-1]:=a[i-1] div 10;
    end;
   while d[t]=0 do dec(t);
   for i:=t downto 1 do
    write(d[i]);
   close(input);
   close(output);
  end.
