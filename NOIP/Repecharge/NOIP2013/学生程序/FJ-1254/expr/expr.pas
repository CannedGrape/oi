var  a,b:array[0..10000]of string;
    c:array[0..10000]of integer;
         i,j,k:longint; p,q:int64;
    o,s:string;
begin
  assign(input,'expr.in'); assign(output,'expr.out');
  reset(input);rewrite(output);
  readln(s);    k:=1;
  for i:=1 to length(s) do
    begin
     if (s[i]<>'+')and(s[i]<>'*') then
         a[k]:=a[k]+s[i]
     else if (s[i]='+')or(s[i]='*')  then
       begin
         inc(K);
         inc(j);
         case s[i] of
          '+':p:=1;
          '*':p:=2;
         end;
       if (p>c[j-1]) then    begin
         b[j]:=s[i]; c[j]:=p;
       end
         else if (j>1)and(p<=c[j-1]) then begin
           while (p>c[j])and(j>=1) do
             begin
               dec(j);
               a[k]:=b[j];
               inc(k);
               b[j]:=o;
               c[j]:=0;
             end;
           inc(j);  dec(k);
           b[j]:=s[i];
           c[j]:=p;
         end;
    end;
  end;
  for i:=j downto 1 do
    begin
      inc(k);
      a[k]:=b[i];
    end;
    while (a[2]<>'')and(k<>1) do
       for i:=1 to k do
         begin
           if (a[i]='+')or(a[i]='*') then
             begin
               val(a[i-1],q);
                val(a[i-2],p);
               if a[i]='+' then p:=(p+q) mod 10000
                 else p:=p*q mod 10000;;
              str(p,a[i-2]);
              for j:=i-1 to k do
                a[j]:=a[j+1];
              for j:=i-1 to k-1 do
                a[j]:=a[j+1];
           k:=k-2;
           break;
        end;
   end;
  val(a[1],p);
  write(p);
  close(input);close(output);
end.






