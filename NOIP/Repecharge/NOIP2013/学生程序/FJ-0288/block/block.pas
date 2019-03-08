program block;
var i:longint;n:longint;ans:longint;
    a:array[0..100001]of longint;
function sort(l,r:longint):longint;
var i:longint;
begin
  sort:=maxlongint;
  for i:=l to r do if a[i]<sort
  then sort:=a[i];
end;
procedure find(l,r:longint);
var i,j,min:longint;f:boolean;
begin
 f:=true;
 for i:=l to r do if a[i]<>0 then
 begin f:=false;break;end;
 if f then exit;
 while (a[l]=0)and(l<n) do inc(l);
 while (a[r]=0)and(r>1) do dec(r);
 if l>r then exit;if r<1 then exit;
 if l>n then exit;if r>n then exit;
 if l<1 then exit;
 if (l=r)and(a[l]<>0)
        then begin ans:=ans+a[l];
                   a[l]:=0;
                   exit;
             end;
 if l<=r then
 min:=sort(l,r);
 ans:=ans+min;
 for j:=l to r do a[j]:=a[j]-min;
 for i:=l to r do
   if (a[i]=0)and(l<=r)
   and(l>=1)and(r<=n)
   then begin
                  find(l,i-1);
                  find(i+1,r);
                  end;
end;
begin
 assign(input,'block.in');
 assign(output,'block.out');
 reset(input);rewrite(output);
 readln(n);
 for i:=1 to n do read(a[i]);
 find(1,n);
 write(ans);
 close(input);close(output);
end.