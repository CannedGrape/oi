var n,i,zd,f,l,j,ans:longint;a:array[1..100001]of longint;

begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);
   readln(n);zd:=0;f:=1;l:=n;ans:=0;
   for i:=1 to n do
   begin read(a[i]);if a[i]>zd then zd:=a[i];end;
   for i:=1 to zd do
     begin while a[f]=0 do inc(f);
           while a[l]=0 do dec(l);
     for j:=f to l do
         begin if (a[j]=0)and(a[j-1]<>0) then inc(ans);end;
     for j:=f to l do if a[j]>0 then dec(a[j]);



     ans:=ans+1;
     end;
   write(ans);
close(input);
close(output);
end.

