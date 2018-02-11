var s:ansistring;
    a:array[0..20000]of qword;
    i,j,ls,atop:longint;
    t:string;
    ds,x:qword;
begin
 assign(input,'expr.in');reset(input);
 assign(output,'expr.out');rewrite(output);
 readln(s);
 i:=1;ls:=length(s);ds:=0;atop:=0;
 while i<=ls do
 begin
  t:='';
  if s[i]='+' then i:=i+1
     else if s[i]='*' then
             begin
              i:=i+1;
              while (i<=ls)and(s[i]<>'+')and(s[i]<>'*') do begin t:=t+s[i];inc(i); end;
              val(t,x);
              a[atop]:=a[atop]*x;
             end
          else begin
               atop:=atop+1;
               while (i<=ls)and(s[i]<>'+')and(s[i]<>'*') do begin t:=t+s[i];inc(i); end;
               val(t,a[atop]);
               end;
 end;
 for i:=1 to atop do ds:=ds+a[i];
 for i:=1 to 4 do begin a[i]:=ds mod 10;ds:=ds div 10; end;
 while a[i]=0 do dec(i);
 for j:=i downto 1 do write(a[j]);
 close(input);close(output);
end.
