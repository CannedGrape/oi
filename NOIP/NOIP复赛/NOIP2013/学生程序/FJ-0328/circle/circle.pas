var
 a,b,c:array[0..1000000]of longint;
 n,m,k,x,i,j,l,ci,num,ok:longint;
 bo:boolean;
begin
 assign(input,'circle.in'); reset(input);
 assign(output,'circle.out'); rewrite(output);
 readln(n,m,k,x);
 for i:=1 to n-1 do begin a[i]:=i; c[i]:=i; end;
 ci:=1;
 for i:=1 to k do ci:=ci*10;
 for j:=1 to ci do
  begin
   for i:=0 to n-1 do
    begin
     num:=i;
     if num<n-m then b[num+m]:=a[i]
     else b[num-n+m]:=a[i];
    end;
   for i:=0 to n-1 do
    if c[i]=b[i] then inc(l);
   if l=n then begin bo:=true; ok:=j; break; end;
   for i:=0 to n-1 do a[i]:=b[i];
  end;
 if bo then
  begin
   for i:=0 to n-1 do a[i]:=i;
   ok:=ci mod ok;
   for j:=1 to ok do
    begin
     for i:=0 to n-1 do
      begin
       num:=i;
       if num<n-m then b[num+m]:=a[i]
       else b[num-n+m]:=a[i];
      end;
     for i:=0 to n-1 do a[i]:=b[i];
    end;
  end;
 for i:=0 to n-1 do if a[i]=x then writeln(i);
 close(input); close(output);
end.
