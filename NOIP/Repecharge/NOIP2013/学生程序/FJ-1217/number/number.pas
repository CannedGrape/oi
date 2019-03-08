program number;
 var i,j,n,p,max:longint;
     fe,re,ma:array[0..1000000] of longint;
 begin
   assign(input,'number.in');reset(input);
   assign(output,'number.out');rewrite(output);
   fillchar(fe,sizeof(fe),0);
   fillchar(re,sizeof(re),0);
   fillchar(ma,sizeof(ma),0);
   read(n,p);
   for i:=1 to n do
    begin
      read(re[i]);
      re[i]:=re[i]+re[i-1];
      if i=1 then fe[i]:=re[i]
       else
        begin
          max:=-maxlongint;
          for j:=i-1 downto 1 do
           if ma[j]>max then max:=ma[j];
          fe[i]:=max;
        end;
      ma[i]:=(re[i]+fe[i]) mod p;
    end;
   max:=-maxlongint;
   for i:=1 to n do
    if fe[i]>max then max:=fe[i];
   write(max);
   close(input);
   close(output);
 end.