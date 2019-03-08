var m:array[0..400000]of longint;
a,b:array[0..100000]of longint;
i,j,k,n,l,t:longint;
tot:int64;
f:boolean;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;
procedure edit(k,q,p,x,y:longint);
begin
 if(q>x)or(p<x)then exit;
 if (q=p)and(p=x)then
  begin
   m[k]:=m[k]-y;
   exit;
  end;
 edit(k*2,q,(q+p)div 2,x,y);
 edit(k*2+1,(q+p)div 2+1,p,x,y);
 m[k]:=min(m[k*2],m[k*2+1]);
end;
function search(k,q,p,x,y:longint):longint;
begin
 if(q>y)or(p<x)then exit;
 if (x<=q)and(y>=p) then exit(m[k]);
 search:=min(search(k*2,q,(q+p)div 2,x,y),
 search(k*2+1,(q+p)div 2+1,p,x,y));
end;
begin
 assign(input,'block.in');reset(input);
 assign(output,'block.out');rewrite(output);
 readln(n);
 for i:=1 to n do
  begin
   read(a[i]);edit(1,1,n,i,-a[i]);
  end;
 b:=a;tot:=0;
 f:=true;
 while f do
  begin
   i:=0;j:=0;t:=1;f:=false;
   while i<=n do
    begin
     inc(i);
     if a[i]>0 then inc(j)
     else
      begin
       if j>0 then
        begin
         k:=search(1,1,n,t,t+j-1)-(b[t]-a[t]);
         inc(tot,k);
         for l:=t to t+j-1 do dec(a[l],k);
        end;
      j:=0;t:=i+1;
     end;
   end;
   i:=n;
   for i:=1 to n do if a[i]>0 then begin f:=true;break;end;
  end;
 writeln(tot);
 close(input);close(output);
end.